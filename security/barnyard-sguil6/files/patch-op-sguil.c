--- src/output-plugins/op_sguil.c.orig	Sat Apr  3 13:57:33 2004
+++ src/output-plugins/op_sguil.c	Mon Jan 23 18:22:09 2006
@@ -1,8 +1,9 @@
-/* $Id: op_sguil.c,v 1.5 2004/04/03 19:57:33 andrewbaker Exp $ */
+/* $Id: op_sguil.c,v 1.16 2005/09/01 15:17:56 bamm Exp $ */
+
 /*
-** Copyright (C) 2001-2002 Andrew R. Baker <andrewb@snort.org>
+** Copyright (C) 2002-2005 Robert (Bamm) Visscher <bamm@sguil.net> 
 **
-** This program is distributed under the terms of version 1.0 of the 
+** This program is distributed under the terms of version 1.0 of the
 ** Q Public License.  See LICENSE.QPL for further details.
 **
 ** This program is distributed in the hope that it will be useful,
@@ -11,21 +12,16 @@
 **
 */
 
-/* op_sguil is a modified op_acid_db plugin configured to work with
- * sguil (Snort GUI for Lamerz). Sguil and ACIDs DB schemas differ.
- * Sguil combines the event and iphdr tables along with moving the
- * src and dst port columns into event. I've also added SguilSendEvent
- * which opens a network socket and sends RT events to sguild.
- *
- * Andrew, sorry about mangling your code but it works so well :)
- *
- * Bammkkkk
+/*
+** op_sguil is the sguil  output plugin for barnyard (http://barnyard.sf.net).
+** For more information about sguil see http://www.sguil.net
 */
 
-/*  I N C L U D E S  *****************************************************/
-
-#ifdef ENABLE_MYSQL /* Wrap the whole thing in an ENABLE_MYSQL block */
+/*********************************************************************
+*                I  N  C  L  U  D  E  S                              *
+*********************************************************************/
 
+/* Std includes */
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
@@ -48,52 +44,13 @@
 #include "op_decode.h"
 #include "event.h"
 
-/* Needed for network socket */
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
 
-#ifdef ENABLE_MYSQL
-#include <mysql.h>
-#include <errmsg.h>
-#endif /* ENABLE_MYSQL */
-
-/*  D A T A   S T R U C T U R E S  **************************************/
-typedef struct _OpSguil_Data 
-{
-    u_int8_t flavor;  /* what flavor of db?  MySQL, postgres, ... */
-    u_int16_t unused;
-    char *server;
-    char *database;
-    char *user;
-    char *password;
-    int sensor_id;
-    int options;
-    char *sguild_host;
-    int sguild_sock;
-    int sguild_port;
-    int nospin;
-    u_int32_t event_id;
-    /* db handles go here */
-#ifdef ENABLE_MYSQL
-    MYSQL *mysql;
-#endif /* ENABLE_MYSQL */
-} OpSguil_Data;
-
-
-#define MAX_QUERY_SIZE 8192
-#define SYSLOG_BUF 1024
-
-/* database flavor defines */
-#define FLAVOR_MYSQL    1
-#define FLAVOR_POSTGRES 2
-
-static char *sgdb_flavours[] = {NULL, "mysql", "postgres"};
-
-/* Network socket defines */
-#define MAX_MSG_LEN 100
-
+/* Yeah TCL! */
+#include <tcl.h>
 
 /* Output plug-in API functions */
 static int OpSguil_Setup(OutputPlugin *, char *args);
@@ -103,56 +60,39 @@
 static int OpSguil_Log(void *, void *);
 static int OpSguil_LogConfig(OutputPlugin *outputPlugin);
 
-/* Internal functions */
-int SguildConnect(OpSguil_Data *);
-int SguilSendEvent(OpSguil_Data *data, char *eventMsg);
-int read_line();
-OpSguil_Data *OpSguil_ParseArgs(char *);
-int sgDbClose(OpSguil_Data *data);
-int sgDbConnect(OpSguil_Data *data);
-u_int32_t SguilGetNextCid(OpSguil_Data *data);
-u_int32_t SguilGetSensorId(OpSguil_Data *data);
-int SguilCheckSchemaVersion(OpSguil_Data *data);
-int InsertIPData(OpSguil_Data *data, Packet *p);
-int sgInsertICMPData(OpSguil_Data *data, Packet *p);
-int sgInsertUDPData(OpSguil_Data *data, Packet *p);
-int sgInsertTCPData(OpSguil_Data *data, Packet *p);
-int sgInsertPayloadData(OpSguil_Data *data, Packet *p);
-
-int sgSelectAsUInt(OpSguil_Data *data, char *sql, unsigned int *result);
-int sgInsert(OpSguil_Data *data, char *sql, unsigned int *row_id);
-int sgBeginTransaction(OpSguil_Data *);
-int sgEndTransaction(OpSguil_Data *);
-int sgAbortTransaction(OpSguil_Data *);
-
-#ifdef ENABLE_MYSQL
-int sgMysqlConnect(OpSguil_Data *);
-int sgMysqlClose(MYSQL *mysql);
-int sgMysqlSelectAsUInt(MYSQL *mysql, char *sql, unsigned int *result);
-int sgMysqlInsert(MYSQL *mysql, char *sql, unsigned int *row_id);
-#endif
+typedef struct _OpSguil_Data
+{
+    char *sensor_name;
+    char *tag_path;
+    char *passwd;
+    u_int16_t sensor_id;
+    u_int32_t event_id;
+    u_int16_t agent_port;
+    int agent_sock;
+} OpSguil_Data;
 
-/* Global variables */
-static char sql_buffer[MAX_QUERY_SIZE];
+#define MAX_MSG_LEN 2048
+#define STD_BUFFER 128
 
-/* 
- * Rather than using an incremental connection id (cid), this uses the
- * current time in milliseconds. BY is fast, but will we get dups in the
- * same millisecond?
- * Okay, lets wait on doing this.
-long GetMilliseconds() 
-{
-    struct timeval  tv;
-    gettimeofday(&tv, NULL);
+int OpSguil_AppendIPHdrData(Tcl_DString *list, Packet *p);
+int OpSguil_AppendICMPData(Tcl_DString *list, Packet *p);
+int OpSguil_AppendTCPData(Tcl_DString *list, Packet *p);
+int OpSguil_AppendUDPData(Tcl_DString *list, Packet *p);
+int OpSguil_AppendPayloadData(Tcl_DString *list, Packet *p);
+int OpSguil_SensorAgentConnect(OpSguil_Data *);
+//int OpSguil_SensorAgentAuth(OpSguil_Data *);
+int OpSguil_SensorAgentInit(OpSguil_Data *);
+int OpSguil_RTEventMsg(OpSguil_Data *data, char *msg);
+int OpSguil_SendAgentMsg(OpSguil_Data *data, char *msg);
+int OpSguil_RecvAgentMsg();
+OpSguil_Data *OpSguil_ParseArgs(char *);
 
-    return (long)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
-}*/
 
 /* init routine makes this processor available for dataprocessor directives */
 void OpSguil_Init()
 {
     OutputPlugin *outputPlugin;
-
+                                                                                                                          
     outputPlugin = RegisterOutputPlugin("sguil", "log");
     outputPlugin->setupFunc = OpSguil_Setup;
     outputPlugin->exitFunc = OpSguil_Exit;
@@ -160,25 +100,9 @@
     outputPlugin->stopFunc = OpSguil_Stop;
     outputPlugin->outputFunc = OpSguil_Log;
     outputPlugin->logConfigFunc = OpSguil_LogConfig;
-    
+                                                                                                                          
 }
 
-int OpSguil_LogConfig(OutputPlugin *outputPlugin)
-{
-    OpSguil_Data *data = NULL;
-
-    if(!outputPlugin || !outputPlugin->data)
-        return -1;
-
-    data = (OpSguil_Data *)outputPlugin->data;
-    
-    LogMessage("OpSguil configured\n");
-    /* XXX We need to print the configuration details here */
-    return 0;
-}
-    
-
-
 /* Setup the output plugin, process any arguments, link the functions to
  * the output functional node
  */
@@ -186,11 +110,11 @@
 {
     /* setup the run time context for this output plugin */
     outputPlugin->data = OpSguil_ParseArgs(args);
-
+                                                                                                                          
     return 0;
 }
-
-/* Inverse of the setup function, free memory allocated in Setup 
+                                                                                                                          
+/* Inverse of the setup function, free memory allocated in Setup
  * can't free the outputPlugin since it is also the list node itself
  */
 int OpSguil_Exit(OutputPlugin *outputPlugin)
@@ -198,478 +122,353 @@
     return 0;
 }
 
-/* 
+/*
  * this function gets called at start time, you should open any output files
  * or establish DB connections, etc, here
  */
 int OpSguil_Start(OutputPlugin *outputPlugin, void *spool_header)
 {
-    char tmpMsg [256];
     OpSguil_Data *data = (OpSguil_Data *)outputPlugin->data;
-    LogMessage("OpSguil_Start\n");
 
     if(data == NULL)
         FatalError("ERROR: Unable to find context for Sguil startup!\n");
+                                                                                                                          
+    if(pv.verbose)
+        OpSguil_LogConfig(outputPlugin);
+                                                                                                                          
+    /* Figure out out sensor_name */
+    if(data->sensor_name == NULL)
+    {
+         /* See if the user used the ProgVar config hostname: */
+         if(pv.hostname != NULL)
+         {
+             data->sensor_name = pv.hostname;
+         }
+         else
+         {
+             FatalError("ERROR: Unable to determine hostname.");
+         }
+    }
+   
+    /* Connect to sensor_agent */
+    OpSguil_SensorAgentConnect(data);
+
+    /* Initialize - get sid and next cid */
+    if(pv.verbose)
+        LogMessage("Waiting for sid and cid from sensor_agent.\n");
+    OpSguil_SensorAgentInit(data);
 
-    /* Connect to sguild */
-    if(SguildConnect(data))
-      FatalError("OpSguil_: Failed to connect to sguild: %s:%i\n",
-        data->sguild_host, data->sguild_port);
-
-    /* Write a system-info message*/
-    sprintf(tmpMsg, "RTEvent |||system-info|%s||Barnyard started.||||||||\n", pv.hostname);
-    SguilSendEvent(data, tmpMsg);
-    
-    /* Connect to the database */
-    if(sgDbConnect(data))
-        FatalError("OpSguil_: Failed to connect to database: %s:%s@%s/%s\n",
-                data->user, data->password, data->server, data->database);
-
-    /* check the db schema */
-    /*if(SguilCheckSchemaVersion(data))
-        FatalError("OpSguil_: database schema mismatch\n");*/
- 
-    /* if sensor id == 0, then we attempt attempt to determine it dynamically */
-    if(data->sensor_id == 0)
-    {
-        data->sensor_id = SguilGetSensorId(data);
-        /* XXX: Error checking */
-    }
-    /* Get the next cid from the database */
-    data->event_id = SguilGetNextCid(data);
     if(pv.verbose)
     {
-        LogMessage("OpAcidDB configuration details\n");
-        LogMessage("Database Flavour: %s\n", sgdb_flavours[data->flavor]);
-        LogMessage("Database Server: %s\n", data->server);
-        LogMessage("Database User: %s\n", data->user);
-        LogMessage("SensorID: %i\n", data->sensor_id);
-        LogMessage("Sguild Host: %s\n", data->sguild_host);
-        LogMessage("Sguild Port: %i\n", data->sguild_port);
-    }
-    if((data->nospin) == NULL)
-    {
-        if(pv.verbose)
-        {
-            LogMessage("Barnyard will sleep(15) if unable to connect to sguild.\n");
-        }
-        data->nospin = 0;
-    }
-    else
-    {
-        if(pv.verbose)
-        {
-            LogMessage("Spinning disabled.\n");
-        }
+
+        LogMessage("Sensor Name: %s\n", data->sensor_name);
+        LogMessage("Agent Port: %u\n", data->agent_port);
+
     }
 
-    sprintf(tmpMsg, "RTEvent |||system-info|%s||Database Server: %s.||||||||\n",
-		   pv.hostname, data->server);
-    SguilSendEvent(data, tmpMsg);
-
-    sprintf(tmpMsg, "RTEvent |||system-info|%s||Database Next CID: %i.||||||||\n",
-		    pv.hostname, data->event_id);
-    SguilSendEvent(data, tmpMsg);
+/*
+**    if(SensorAgentAuth(data))
+**        FatalError("OpSguil: Authentication failed.\n");
+**
+**    if(pv.verbose)
+**        LogMessage("OpSguil: Authentication successful.);
+*/
+
     return 0;
 }
 
 int OpSguil_Stop(OutputPlugin *outputPlugin)
 {
     OpSguil_Data *data = (OpSguil_Data *)outputPlugin->data;
-
+                                                                                                                          
     if(data == NULL)
         FatalError("ERROR: Unable to find context for Sguil startup!\n");
+                                                                                                                          
+    return 0;
+}
+
+int OpSguil_LogConfig(OutputPlugin *outputPlugin)
+{
+
+    OpSguil_Data *data = NULL;
+                                                                                                                                           
+    if(!outputPlugin || !outputPlugin->data)
+        return -1;
+                                                                                                                                           
+    data = (OpSguil_Data *)outputPlugin->data;
+
+    LogMessage("OpSguil configured\n");
+
+    /* XXX We need to print the configuration details here */
 
-    /* close database connection */
-    sgDbClose(data);
-    
     return 0;
 }
 
-/* sguil only uses log */
-int OpSguil_Log(void *context, void *data)
+
+int OpSguil_Log(void *context, void *ul_data)
 {
+
     char timestamp[TIMEBUF_SIZE];
-    char syslogMessage[SYSLOG_BUF];
-    char eventInfo[SYSLOG_BUF];
-    //int MAX_INSERT_LEN = 1024;
-    char insertColumns[MAX_QUERY_SIZE];
-    char insertValues[MAX_QUERY_SIZE];
-    char valuesTemp[MAX_QUERY_SIZE];
-    char ipInfo[38];
-    char portInfo[16];
-    char *esc_message;
     Sid *sid = NULL;
     ClassType *class_type;
-    UnifiedLogRecord *record = (UnifiedLogRecord *)data; 
-    OpSguil_Data *op_data = (OpSguil_Data *)context;
+    UnifiedLogRecord *record = (UnifiedLogRecord *)ul_data;
+    OpSguil_Data *data = (OpSguil_Data *)context;
     Packet p;
+    char buffer[STD_BUFFER];
+    Tcl_DString list;
 
-    bzero(syslogMessage, SYSLOG_BUF);
-    bzero(insertColumns, MAX_QUERY_SIZE);
-    bzero(insertValues, MAX_QUERY_SIZE);
-
-#if 0 /* this is broken */
-    /* skip tagged packets, since the db does not have a mechanism to 
-     * deal with them properly
-     */
-    if(record->log.event.event_reference)
-    {
-        LogMessage("Skipping tagged packet %i\n", record->log.event.event_reference);
-        return 0;
-    }
-#endif
+    bzero(buffer, STD_BUFFER);
 
+    //LogMessage("Event id ==> %u\n", record->log.event.event_id);
+    //LogMessage("Ref time ==> %lu\n", record->log.event.ref_time.tv_sec);
 
-    RenderTimestamp(record->log.pkth.ts.tv_sec, timestamp, TIMEBUF_SIZE);
-    //fprintf(stdout, "Timestamp: %lu\n", GetMilliseconds());
-    //fflush(stdout);
+    /* Sig info */
     sid = GetSid(record->log.event.sig_generator, record->log.event.sig_id);
     if(sid == NULL)
         sid = FakeSid(record->log.event.sig_generator, record->log.event.sig_id);
+    sid->rev = record->log.event.sig_rev;
+
     class_type = GetClassType(record->log.event.classification);
+    
+    /* Here we build our RT event to send to sguild. The event is built with a
+    ** proper tcl list format. 
+    ** RT FORMAT:
+    ** 
+    **     0      1    2     3          4            5                  6                7
+    ** {RTEVENT} {0} {sid} {cid} {sensor name} {snort event_id} {snort event_ref} {snort ref_time} 
+    **
+    **     8         9      10      11         12         13          14
+    ** {sig_gen} {sig id} {rev} {message} {timestamp} {priority} {class_type} 
+    **
+    **      15            16           17           18           19       20        21
+    ** {sip (dec)} {sip (string)} {dip (dec)} {dip (string)} {ip proto} {ip ver} {ip hlen}
+    **
+    **    22       23      24        25        26       27       28
+    ** {ip tos} {ip len} {ip id} {ip flags} {ip off} {ip ttl} {ip csum}
+    **
+    **      29         30           31        32         33
+    ** {icmp type} {icmp code} {icmp csum} {icmp id} {icmp seq}
+    ** 
+    **     34         35
+    ** {src port} {dst port}
+    **
+    **     36        37        38        39        40         41        42          43
+    ** {tcp seq} {tcp ack} {tcp off} {tcp res} {tcp flags} {tcp win} {tcp csum} {tcp urp}
+    **
+    **     44        45
+    ** {udp len} {udp csum}
+    **
+    **      46
+    ** {data payload}
+    */
+
+    Tcl_DStringInit(&list);
+
+    /* RTEVENT */
+    Tcl_DStringAppendElement(&list, "RTEVENT");
+
+    /* Status - 0 */
+    Tcl_DStringAppendElement(&list, "0");
+
+    /* Sensor ID  (sid) */
+    sprintf(buffer, "%u", data->sensor_id);
+    Tcl_DStringAppendElement(&list, buffer);
+
+    /* Event ID (cid) */
+    sprintf(buffer, "%u", data->event_id);
+    Tcl_DStringAppendElement(&list, buffer);
+
+    /* Sensor Name */
+    Tcl_DStringAppendElement(&list, data->sensor_name);
+
+    /* Snort Event ID */
+    sprintf(buffer, "%u", record->log.event.event_id);
+    Tcl_DStringAppendElement(&list, buffer);
+
+    /* Snort Event Ref */
+    sprintf(buffer, "%u", record->log.event.event_reference);
+    Tcl_DStringAppendElement(&list, buffer);
+
+    /* Snort Event Ref Time */
+    if(record->log.event.ref_time.tv_sec == 0) 
+    {
+        Tcl_DStringAppendElement(&list, "");
+    }
+    else
+    {    
+        RenderTimestamp(record->log.event.ref_time.tv_sec, timestamp, TIMEBUF_SIZE);
+        Tcl_DStringAppendElement(&list, timestamp);
+    }
+
+    /* Generator ID */
+    sprintf(buffer, "%d", sid->gen);
+    Tcl_DStringAppendElement(&list, buffer);
+
+    /* Signature ID */
+    sprintf(buffer, "%d", sid->sid);
+    Tcl_DStringAppendElement(&list, buffer);
+
+    /* Signature Revision */
+    sprintf(buffer, "%d", sid->rev);
+    Tcl_DStringAppendElement(&list, buffer);
+
+    /* Signature Msg */
+    Tcl_DStringAppendElement(&list, sid->msg);
+
+    /* Packet Timestamp */
+    RenderTimestamp(record->log.pkth.ts.tv_sec, timestamp, TIMEBUF_SIZE);
+    Tcl_DStringAppendElement(&list, timestamp);
+
+    /* Alert Priority */
+    sprintf(buffer, "%u", record->log.event.priority);
+    Tcl_DStringAppendElement(&list, buffer);
 
-    //sgBeginTransaction(op_data); /* XXX: Error checking */
-    /* Build the event insert. */
-    snprintf(insertColumns, MAX_QUERY_SIZE,
-            "INSERT INTO event (status, sid, cid, signature_id, signature_rev, signature, timestamp, priority, class");
-
-    esc_message = malloc(strlen(sid->msg)*2+1);
-    mysql_real_escape_string(op_data->mysql, esc_message, sid->msg, strlen(sid->msg));
-
-    if(class_type == NULL)
-    {
-        snprintf(valuesTemp, MAX_QUERY_SIZE,
-                "VALUES ('0', '%u', '%u', '%d', '%d', '%s', '%s', '%u', 'unknown'",
-                op_data->sensor_id, op_data->event_id, sid->sid, sid->rev, esc_message, timestamp, 
-                record->log.event.priority);
-        snprintf(eventInfo, SYSLOG_BUF, "RTEvent |0|%u|unknown|%s|%s|%u|%u|%s",
-                record->log.event.priority, 
-                pv.hostname, timestamp, op_data->sensor_id, op_data->event_id,
-                sid->msg);
+    /* Alert Classification */
+    if (class_type == NULL)
+    {
+        Tcl_DStringAppendElement(&list, "unknown");
     }
     else
     {
-        snprintf(valuesTemp, MAX_QUERY_SIZE,
-                "VALUES ('0', '%u', '%u', '%d', '%d', '%s', '%s', '%u', '%s'",
-                op_data->sensor_id, op_data->event_id, sid->sid, sid->rev, esc_message, timestamp, 
-                record->log.event.priority, class_type->type);
-        snprintf(eventInfo, SYSLOG_BUF, "RTEvent |0|%u|%s|%s|%s|%u|%u|%s",
-                record->log.event.priority, class_type->type,
-                pv.hostname, timestamp, op_data->sensor_id, op_data->event_id,
-                sid->msg);
-    }
-
-    free(esc_message);
-
-    insertValues[0] = '\0';
-    strcat(insertValues, valuesTemp);
-
-    syslogMessage[0] = '\0';
-    strcat(syslogMessage, eventInfo);
-    /* decode the packet */
+        Tcl_DStringAppendElement(&list, class_type->type);
+    }
+
+    /* Pull decoded info from the packet */
     if(DecodePacket(&p, &record->log.pkth, record->pkt + 2) == 0)
     {
-
         if(p.iph)
         {
-            /* Insert ip header information */
-            //InsertIPData(op_data, &p);
-            strcat(insertColumns,
-                    ",src_ip, dst_ip, ip_proto, ip_ver, ip_hlen, ip_tos, ip_len, ip_id, ip_flags, ip_off, ip_ttl, ip_csum");
-            snprintf(valuesTemp, MAX_QUERY_SIZE,
-                    ",'%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u'",
-                    ntohl(p.iph->ip_src.s_addr), ntohl(p.iph->ip_dst.s_addr), p.iph->ip_proto, IP_VER(p.iph),
-                    IP_HLEN(p.iph), p.iph->ip_tos, ntohs(p.iph->ip_len), ntohs(p.iph->ip_id),
-#if defined(WORDS_BIGENDIAN)
-                    ((p.iph->ip_off & 0xE000) >> 13),
-                    htons(p.iph->ip_off & 0x1FFF),
-#else
-                    ((p.iph->ip_off & 0x00E0) >> 5),
-                    htons(p.iph->ip_off & 0xFF1F),
-#endif
-                    p.iph->ip_ttl,
-                    htons(p.iph->ip_csum) < MAX_QUERY_SIZE);
-
-            strcat(insertValues, valuesTemp);
-
+            int i;
 
-            /* SYSLOG - Changed to SguilSendEvent*/
-            snprintf(ipInfo, 38, "|%u.%u.%u.%u|%u.%u.%u.%u|%u",
-#if defined(WORDS_BIGENDIAN)
-                    (p.iph->ip_src.s_addr & 0xff000000) >> 24,
-                    (p.iph->ip_src.s_addr & 0x00ff0000) >> 16,
-                    (p.iph->ip_src.s_addr & 0x0000ff00) >> 8,
-                    (p.iph->ip_src.s_addr & 0x000000ff),
-                    (p.iph->ip_dst.s_addr & 0xff000000) >> 24,
-                    (p.iph->ip_dst.s_addr & 0x00ff0000) >> 16,
-                    (p.iph->ip_dst.s_addr & 0x0000ff00) >> 8,
-                    (p.iph->ip_dst.s_addr & 0x000000ff),
-#else
-                    (p.iph->ip_src.s_addr & 0x000000ff),
-                    (p.iph->ip_src.s_addr & 0x0000ff00) >> 8,
-                    (p.iph->ip_src.s_addr & 0x00ff0000) >> 16,
-                    (p.iph->ip_src.s_addr & 0xff000000) >> 24,
-                    (p.iph->ip_dst.s_addr & 0x000000ff),
-                    (p.iph->ip_dst.s_addr & 0x0000ff00) >> 8,
-                    (p.iph->ip_dst.s_addr & 0x00ff0000) >> 16,
-                    (p.iph->ip_dst.s_addr & 0xff000000) >> 24,
-#endif
-                    p.iph->ip_proto);
-            strcat(syslogMessage, ipInfo);
+            /* Add IP header */
+            OpSguil_AppendIPHdrData(&list, &p);
 
-            /* store layer 4 data for non fragmented packets */
+            /* Add icmp || udp || tcp data */
             if(!(p.pkt_flags & PKT_FRAG_FLAG))
             {
+
                 switch(p.iph->ip_proto)
                 {
                     case IPPROTO_ICMP:
-                        snprintf(portInfo, 16, "|||");
-                        if(!p.icmph) 
-                            break;
-                        strcat(insertColumns,
-                                ", icmp_type, icmp_code)");
-                        snprintf(valuesTemp, MAX_QUERY_SIZE,
-                                ", '%u', '%u')", p.icmph->icmp_type,
-                                p.icmph->icmp_code);
-                        strcat(insertValues, valuesTemp);
-                        strcat(insertColumns, insertValues);
-                        sgInsert(op_data, insertColumns, NULL);
-                        sgInsertICMPData(op_data, &p);
+                        OpSguil_AppendICMPData(&list, &p);
                         break;
+
                     case IPPROTO_TCP:
-                        strcat(insertColumns,
-                                ", src_port, dst_port)");
-                        snprintf(valuesTemp, MAX_QUERY_SIZE,
-                                ", '%u', '%u')", p.sp, p.dp);
-                        strcat(insertValues, valuesTemp);
-                        strcat(insertColumns, insertValues);
-                        sgInsert(op_data, insertColumns, NULL);
-                        sgInsertTCPData(op_data, &p);
-                        snprintf(portInfo, 16, "|%u|%u|",
-                                p.sp, p.dp);
+                        OpSguil_AppendTCPData(&list, &p);
                         break;
+
                     case IPPROTO_UDP:
-                        strcat(insertColumns,
-                                ", src_port, dst_port)");
-                        snprintf(valuesTemp, MAX_QUERY_SIZE,
-                                ", '%u', '%u')", p.sp, p.dp);
-                        strcat(insertValues, valuesTemp);
-                        strcat(insertColumns, insertValues);
-                        sgInsert(op_data, insertColumns, NULL);
-                        sgInsertUDPData(op_data, &p);
-                        snprintf(portInfo, 16, "|%u|%u|",
-                                p.sp, p.dp);
+                        OpSguil_AppendUDPData(&list, &p);
+                        break;
+
+                    default:
+                        for(i = 0; i < 17; ++i)
+                        {
+                            Tcl_DStringAppendElement(&list, "");
+                        }
                         break;
                 }
-                strcat(syslogMessage, portInfo);
+
             }
             else
             {
-                strcat(syslogMessage, "|||");
+                /* Null out TCP/UDP/ICMP fields */
+                for(i = 0; i < 17; ++i)
+                {
+                    Tcl_DStringAppendElement(&list, "");
+                }
             }
-
-
-            /* Insert payload data */
-            sgInsertPayloadData(op_data, &p);
         }
         else
         {
-            strcat(syslogMessage, "||||||");
+
+            /* No IP Header. */
+            int i;
+            for(i = 0; i < 31; ++i)
+            {
+                Tcl_DStringAppendElement(&list, "");
+            }
         }
-    }
 
-    //sgEndTransaction(op_data);  /* XXX: Error Checking */
-    ++op_data->event_id;
-    /* Append the sig id and rev to the RT event */
-    snprintf(eventInfo, SYSLOG_BUF, "%u|%u|\n", sid->sid, sid->rev);
-    strcat(syslogMessage, eventInfo);
-    /* Write to the network socket */
-    SguilSendEvent(op_data, syslogMessage);
-    return 0;
-}
+        /* Add payload data */
+        OpSguil_AppendPayloadData(&list, &p);
 
-int sgInsertUDPData(OpSguil_Data *op_data, Packet *p)
-{
-    if(!p->udph)
-        return 0;
-        if(snprintf(sql_buffer, MAX_QUERY_SIZE,
-                "INSERT INTO udphdr(sid, cid, udp_len, udp_csum)"
-	        "VALUES ('%u', '%u', '%u', '%u')", 
-                op_data->sensor_id, op_data->event_id,
-                ntohs(p->udph->uh_len), 
-                ntohs(p->udph->uh_chk)) < MAX_QUERY_SIZE)
+    }
+    else
+    {
+        /* ack! an event without a packet. Append 32 fillers */
+        int i;
+        for(i = 0; i < 32; ++i)
         {
-            sgInsert(op_data, sql_buffer, NULL);  /* XXX: Error Checking */
+            Tcl_DStringAppendElement(&list, "");
         }
-    return 0;
-}
+    }
 
-int sgInsertTCPData(OpSguil_Data *op_data, Packet *p)
-{
-    if(!p->tcph)
-        return 0;
+    /* Send msg to sensor_agent */
+    if (OpSguil_RTEventMsg(data, Tcl_DStringValue(&list)))
+        FatalError("Unable to send RT Events to sensor agent.\n");
 
-    /* insert data into the tcp header table */
-        if(snprintf(sql_buffer, MAX_QUERY_SIZE,
-                "INSERT INTO tcphdr(sid, cid, tcp_seq, "
-                "tcp_ack, tcp_off, tcp_res, tcp_flags, tcp_win, tcp_csum, "
-                "tcp_urp) VALUES('%u', '%u', '%u', '%u', '%u', "
-                "'%u', '%u', '%u', '%u', '%u')",
-                op_data->sensor_id, op_data->event_id,
-                ntohl(p->tcph->th_seq), ntohl(p->tcph->th_ack),
-                TCP_OFFSET(p->tcph), TCP_X2(p->tcph), p->tcph->th_flags,
-                ntohs(p->tcph->th_win), ntohs(p->tcph->th_sum),
-                ntohs(p->tcph->th_urp)) < MAX_QUERY_SIZE)
-        {
-            sgInsert(op_data, sql_buffer, NULL);  /* XXX: Error checking */
-        }
-        /* XXX: TCP Options not handled */
-    return 0;
-}
+    /* Free! */
+    Tcl_DStringFree(&list);
+
+    /* bump the event id */
+    ++data->event_id;
 
-int sgInsertICMPData(OpSguil_Data *op_data, Packet *p)
-{
-    if(!p->icmph)
-        return 0;
-        if(p->icmph->icmp_type == 0 || p->icmph->icmp_type == 8 ||
-                p->icmph->icmp_type == 13 || p->icmph->icmp_type == 14 ||
-                p->icmph->icmp_type == 15 || p->icmph->icmp_type == 16)
-        {
-            if(snprintf(sql_buffer, MAX_QUERY_SIZE,
-                    "INSERT INTO icmphdr(sid, cid, "
-                    "icmp_csum, icmp_id, icmp_seq) "
-                    "VALUES('%u', '%u', '%u', '%u', '%u')", 
-                    op_data->sensor_id, op_data->event_id, 
-                    ntohs(p->icmph->icmp_csum),
-                    htons(p->icmph->icmp_hun.ih_idseq.icd_id),
-                    htons(p->icmph->icmp_hun.ih_idseq.icd_seq)) 
-                    < MAX_QUERY_SIZE)
-            {
-                sgInsert(op_data, sql_buffer, NULL);  /* XXX: Error checking */
-            }
-        }
-        else
-        {
-            if(snprintf(sql_buffer, MAX_QUERY_SIZE,
-                    "INSERT INTO icmphdr(sid, cid, "
-                    "icmp_csum) VALUES('%u', '%u', '%u')", 
-                    op_data->sensor_id, op_data->event_id,
-                    ntohs(p->icmph->icmp_csum))
-                    < MAX_QUERY_SIZE)
-            {
-                sgInsert(op_data, sql_buffer, NULL);  /* XXX: Error Checking */
-            }
-        }
     return 0;
 }
 
-int sgInsertPayloadData(OpSguil_Data *op_data, Packet *p)
+int OpSguil_RTEventMsg(OpSguil_Data *data, char *msg)
 {
-    char *hex_payload;
-    if(p->dsize)
-    {
-        hex_payload = fasthex(p->data, p->dsize);
-        if(snprintf(sql_buffer, MAX_QUERY_SIZE,
-                "INSERT INTO data(sid, cid, data_payload) "
-                "VALUES('%u', '%u', '%s')", op_data->sensor_id, 
-                op_data->event_id, hex_payload) < MAX_QUERY_SIZE)
-        {
-            sgInsert(op_data, sql_buffer, NULL);  /* XXX: Error Checking */
-        }
-        free(hex_payload);
-    }
-    return 0;
-}
 
+    char tmpRecvMsg[MAX_MSG_LEN];
 
-/* Attempts to retrieve the sensor id
- */
-unsigned int SguilGetSensorId(OpSguil_Data *op_data)
-{
-    unsigned int sensor_id = 0;
-    /* XXX:  This should be moved to global setup */
-    if(pv.hostname == NULL)
-    {
-        /* query the hostname */
-        /* the DB schema allows for a hostname of up to 2^16-1 characters, i am limiting
-         * this to 255 (+1 for the NULL)
-         */
-        pv.hostname = (char *)malloc(256);
-        if(gethostname(pv.hostname, 256))
-        {
-            FatalError("Error querying hostname: %s\n", strerror(errno));
-        }
-    }
+    /* Send Msg */
+    OpSguil_SendAgentMsg(data, msg);
 
-    /* XXX: need to escape strings */
-    if(snprintf(sql_buffer, MAX_QUERY_SIZE, 
-                "SELECT sid FROM sensor WHERE hostname='%s'"
-                , pv.hostname) < MAX_QUERY_SIZE)
+    /* Get confirmation */
+    memset(tmpRecvMsg,0x0,MAX_MSG_LEN);
+    if(OpSguil_RecvAgentMsg(data, tmpRecvMsg) == 1 )
     {
-        if(sgSelectAsUInt(op_data, sql_buffer, &sensor_id) == -1)
-        {
-            FatalError("Database Error\n");
-        }
-        if(sensor_id == 0)
-        {
 
-            /* insert sensor information */
+        if(pv.verbose)
+         LogMessage("Retrying\n");
+
+        OpSguil_RTEventMsg(data, msg);
 
-            if(snprintf(sql_buffer, MAX_QUERY_SIZE, "INSERT INTO sensor (hostname) "
-                        "VALUES ('%s')", pv.hostname) < MAX_QUERY_SIZE)
-            {
-                sgInsert(op_data, sql_buffer, &sensor_id); 
-                /* XXX: Error checking */
-            }
-            else
-            {
-                FatalError("Error building SQL Query\n");
-            }
-        }
-        if(pv.verbose >= 2)
-            LogMessage("sensor_id == %u\n", sensor_id);
     }
     else
     {
-        FatalError("Error building SQL Query\n");
-    } 
-    return sensor_id;
-}
 
-/* Retrieves the next acid_cid to use for inserting into the database for this
- * sensor
- */
-unsigned int SguilGetNextCid(OpSguil_Data *data)
-{
-    unsigned int cid = 0;
-    if(snprintf(sql_buffer, MAX_QUERY_SIZE, 
-                "SELECT max(cid) FROM event WHERE sid='%u'", data->sensor_id) 
-            < MAX_QUERY_SIZE)
-    {
-        if(sgSelectAsUInt(data, sql_buffer, &cid) == -1)
+        char **toks;
+        int num_toks;
+
+        if(pv.verbose)
+            LogMessage("Received: %s", tmpRecvMsg);
+
+        /* Parse the response */
+        toks = mSplit(tmpRecvMsg, " ", 2, &num_toks, 0);
+        if(strcasecmp("Confirm", toks[0]) != 0 || atoi(toks[1]) != data->event_id )
         {
-            FatalError("Database Error\n");
+
+            FatalError("Expected Confirm %u and got: %s\n", data->event_id, tmpRecvMsg);
+
         }
-#ifdef DEBUG
-        LogMessage("cid == %u\n", cid); fflush(stdout);
-#endif
+
+        FreeToks(toks, num_toks);
+
     }
-    else
-    {
-        FatalError("Database Error\n");
-    } 
-    return ++cid;
+
+    return 0;
+ 
 }
 
 OpSguil_Data *OpSguil_ParseArgs(char *args)
 {
-    OpSguil_Data *op_data;
 
+    OpSguil_Data *op_data;
+                                                                                                                          
     op_data = (OpSguil_Data *)SafeAlloc(sizeof(OpSguil_Data));
-
-    op_data->options = 0;
-
+                                                                                                                          
     if(args != NULL)
     {
         char **toks;
@@ -685,77 +484,38 @@
             while(isspace((int)*index))
                 ++index;
             stoks = mSplit(index, " ", 2, &num_stoks, 0);
-            if(strcasecmp("database", stoks[0]) == 0)
-            {
-                if(num_stoks > 1 && op_data->database == NULL)
-                    op_data->database = strdup(stoks[1]);
-                else
-                    LogMessage("Argument Error in %s(%i): %s\n", file_name, 
-                            file_line, index);
-            }
-            else if(strcasecmp("server", stoks[0]) == 0)
-            {
-                if(num_stoks > 1 && op_data->server == NULL)
-                    op_data->server = strdup(stoks[1]);
-                else
-                    LogMessage("Argument Error in %s(%i): %s\n", file_name, 
-                            file_line, index);
-            }
-            else if(strcasecmp("user", stoks[0]) == 0)
+            if(strcasecmp("agent_port", stoks[0]) == 0)
             {
-                if(num_stoks > 1 && op_data->user == NULL)
-                    op_data->user = strdup(stoks[1]);
+                if(num_stoks > 1)
+                    op_data->agent_port = atoi(stoks[1]);
                 else
-                    LogMessage("Argument Error in %s(%i): %s\n", file_name, 
+                    LogMessage("Argument Error in %s(%i): %s\n", file_name,
                             file_line, index);
             }
-            else if(strcasecmp("password", stoks[0]) == 0)
+            else if(strcasecmp("tag_path", stoks[0]) == 0)
             {
-                if(num_stoks > 1 && op_data->password == NULL)
-                    op_data->password = strdup(stoks[1]);
+                if(num_stoks > 1 && op_data->tag_path == NULL)
+                    op_data->tag_path = strdup(stoks[1]);
                 else
-                    LogMessage("Argument Error in %s(%i): %s\n", file_name, 
+                    LogMessage("Argument Error in %s(%i): %s\n", file_name,
                             file_line, index);
             }
-            else if(strcasecmp("sensor_id", stoks[0]) == 0)
+            else if(strcasecmp("sensor_name", stoks[0]) == 0)
             {
-                if(num_stoks > 1 && op_data->sensor_id == 0)
-                    op_data->sensor_id = atoi(stoks[1]);
+                if(num_stoks > 1 && op_data->sensor_name == NULL)
+                    op_data->sensor_name = strdup(stoks[1]);
                 else
-                    LogMessage("Argument Error in %s(%i): %s\n", file_name, 
+                    LogMessage("Argument Error in %s(%i): %s\n", file_name,
                             file_line, index);
             }
-	    else if(strcasecmp("sguild_host", stoks[0]) == 0)
-	    {
-		if(num_stoks > 1 && op_data->sguild_host == 0)
-		    op_data->sguild_host = strdup(stoks[1]);
-	        else
-	            LogMessage("Argument Error in %s(%i): %s\n", file_name,
-			    file_line, index);
-	    }
-            else if(strcasecmp("nospin", stoks[0]) == 0)
-            {
-                    op_data->nospin = 1;
-            }
-	    else if(strcasecmp("sguild_port", stoks[0]) == 0)
+            else if(strcasecmp("passwd", stoks[0]) == 0)
             {
-		if(num_stoks > 1 && op_data->sguild_port == 0)
-		    op_data->sguild_port = atoi(stoks[1]);
-	        else
-	            LogMessage("Argument Error in %s(%i): %s\n", file_name,
-			    file_line, index);
-	    }
-
-#ifdef ENABLE_MYSQL
-            else if(strcasecmp("mysql", stoks[0]) == 0)
-            {   
-                if(op_data->flavor == 0)
-                    op_data->flavor = FLAVOR_MYSQL;
+                if(num_stoks > 1 && op_data->passwd == NULL)
+                    op_data->passwd = strdup(stoks[1]);
                 else
-                    LogMessage("Argument Error in %s(%i): %s\n", file_name, 
+                    LogMessage("Argument Error in %s(%i): %s\n", file_name,
                             file_line, index);
             }
-#endif /* ENABLE_MYSQL */
             else
             {
                 fprintf(stderr, "WARNING %s (%d) => Unrecognized argument for "
@@ -765,378 +525,544 @@
         }
         /* free your mSplit tokens */
         FreeToks(toks, num_toks);
-    }
-    if(op_data->flavor == 0)
-    FatalError("You must specify a database flavor\n");
 
-    if (op_data->sguild_host == NULL)
-    {
-	FatalError("You must specify a sguild host.\n");
     }
 
-    if (!op_data->sguild_port)
+    if (op_data->agent_port == 0)
     {
-	FatalError("You must specify a sguild port.\n");
+        op_data->agent_port = 7735;
     }
+
     return op_data;
-}
 
+}
 
-int sgDbConnect(OpSguil_Data *op_data)
+int OpSguil_AppendIPHdrData(Tcl_DString *list, Packet *p)
 {
-    switch(op_data->flavor)
-    {
-#ifdef ENABLE_MYSQL
-        case FLAVOR_MYSQL:
-            return sgMysqlConnect(op_data);
+    char buffer[STD_BUFFER];
+
+    bzero(buffer, STD_BUFFER);
+
+    sprintf(buffer, "%u", ntohl(p->iph->ip_src.s_addr));
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u.%u.%u.%u",
+#if defined(WORDS_BIGENDIAN)
+           (p->iph->ip_src.s_addr & 0xff000000) >> 24,
+           (p->iph->ip_src.s_addr & 0x00ff0000) >> 16,
+           (p->iph->ip_src.s_addr & 0x0000ff00) >> 8,
+           (p->iph->ip_src.s_addr & 0x000000ff));
+#else
+           (p->iph->ip_src.s_addr & 0x000000ff),
+           (p->iph->ip_src.s_addr & 0x0000ff00) >> 8,
+           (p->iph->ip_src.s_addr & 0x00ff0000) >> 16,
+           (p->iph->ip_src.s_addr & 0xff000000) >> 24);
 #endif
-        default:
-            FatalError("Database flavor not supported\n");
-            return 1;
-    }
-//    return 1;
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u", ntohl(p->iph->ip_dst.s_addr));
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u.%u.%u.%u",
+#if defined(WORDS_BIGENDIAN)
+           (p->iph->ip_dst.s_addr & 0xff000000) >> 24,
+           (p->iph->ip_dst.s_addr & 0x00ff0000) >> 16,
+           (p->iph->ip_dst.s_addr & 0x0000ff00) >> 8,
+           (p->iph->ip_dst.s_addr & 0x000000ff));
+#else
+           (p->iph->ip_dst.s_addr & 0x000000ff),
+           (p->iph->ip_dst.s_addr & 0x0000ff00) >> 8,
+           (p->iph->ip_dst.s_addr & 0x00ff0000) >> 16,
+           (p->iph->ip_dst.s_addr & 0xff000000) >> 24);
+#endif
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u", p->iph->ip_proto);
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u", IP_VER(p->iph));
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u", IP_HLEN(p->iph));
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u", p->iph->ip_tos);
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u", ntohs(p->iph->ip_len));
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u", ntohs(p->iph->ip_id));
+    Tcl_DStringAppendElement(list, buffer);
+                                                                                                                                                 
+#if defined(WORDS_BIGENDIAN)
+                                                                                                                                                 
+    sprintf(buffer, "%u", ((p->iph->ip_off & 0xE000) >> 13));
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u", htons(p->iph->ip_off & 0x1FFF));
+    Tcl_DStringAppendElement(list, buffer);
+                                                                                                                                                 
+#else
+                                                                                                                                                 
+    sprintf(buffer, "%u", ((p->iph->ip_off & 0x00E0) >> 5));
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u", htons(p->iph->ip_off & 0xFF1F));
+    Tcl_DStringAppendElement(list, buffer);
+ 
+#endif
+ 
+    sprintf(buffer, "%u", p->iph->ip_ttl);
+    Tcl_DStringAppendElement(list, buffer);
+    sprintf(buffer, "%u", htons(p->iph->ip_csum));
+    Tcl_DStringAppendElement(list, buffer);
+
+    return 0;
 }
 
-int sgDbClose(OpSguil_Data *op_data)
+int OpSguil_AppendICMPData(Tcl_DString *list, Packet *p)
 {
-    switch(op_data->flavor)
+
+    int i;
+    char buffer[STD_BUFFER];
+
+    bzero(buffer, STD_BUFFER);
+
+    if(!p->icmph)
     {
-#ifdef ENABLE_MYSQL
-        case FLAVOR_MYSQL:  
-            return sgMysqlClose(op_data->mysql);
-#endif
-        default:
-            FatalError("Database flavor not supported\n");
-            return 1;
-    }
-}
 
+        /* Null out ICMP fields */
+        for(i=0; i < 5; i++)
+            Tcl_DStringAppendElement(list, "");
 
-int sgSelectAsUInt(OpSguil_Data *op_data, char *sql, unsigned int *result)
-{
-    switch(op_data->flavor)
+    }
+    else
     {
-#ifdef ENABLE_MYSQL
-        case FLAVOR_MYSQL:
-            return sgMysqlSelectAsUInt(op_data->mysql, sql, result);
-#endif
-        default:
-            FatalError("Database flavor not supported\n");
-            return 1;
+
+        /* ICMP type */
+        sprintf(buffer, "%u", p->icmph->icmp_type);
+        Tcl_DStringAppendElement(list, buffer);
+
+        /* ICMP code */
+        sprintf(buffer, "%u", p->icmph->icmp_code);
+        Tcl_DStringAppendElement(list, buffer);
+    
+        /* ICMP CSUM */
+        sprintf(buffer, "%u", ntohs(p->icmph->icmp_csum));
+        Tcl_DStringAppendElement(list, buffer);
+
+        /* Append other ICMP data if we have it */
+        if(p->icmph->icmp_type == ICMP_ECHOREPLY || 
+           p->icmph->icmp_type == ICMP_ECHO ||
+           p->icmph->icmp_type == ICMP_TIMESTAMP ||
+           p->icmph->icmp_type == ICMP_TIMESTAMPREPLY ||
+           p->icmph->icmp_type == ICMP_INFO_REQUEST || 
+           p->icmph->icmp_type == ICMP_INFO_REPLY)
+        {
+
+            /* ICMP ID */
+            sprintf(buffer, "%u", htons(p->icmph->icmp_hun.ih_idseq.icd_id));
+            Tcl_DStringAppendElement(list, buffer);
+
+            /* ICMP Seq */
+            sprintf(buffer, "%u", htons(p->icmph->icmp_hun.ih_idseq.icd_seq));
+            Tcl_DStringAppendElement(list, buffer);
+
+        }
+        else
+        {
+
+            /* Add two empty elements */
+            for(i=0; i < 2; i++)
+                Tcl_DStringAppendElement(list, "");
+    
+        }
+
     }
+
+    /* blank out 12 elements */
+    for(i = 0; i < 12; i++)
+        Tcl_DStringAppendElement(list, "");
+
+    return 0;
+
 }
 
-int sgInsert(OpSguil_Data *op_data, char *sql, unsigned int *row_id)
+int OpSguil_AppendTCPData(Tcl_DString *list, Packet *p)
 {
-    switch(op_data->flavor)
+
+    /*
+    **     33        34        35        36        37         38        39          40
+    ** {tcp seq} {tcp ack} {tcp off} {tcp res} {tcp flags} {tcp win} {tcp csum} {tcp urp}
+    **
+    */
+
+    int i;
+    char buffer[STD_BUFFER];
+
+    bzero(buffer, STD_BUFFER);
+
+    /* empty elements for icmp data */
+    for(i=0; i < 5; i++)
+        Tcl_DStringAppendElement(list, "");
+
+    if(!p->tcph)
     {
-#ifdef ENABLE_MYSQL
-        case FLAVOR_MYSQL:
-            return sgMysqlInsert(op_data->mysql, sql, row_id);
-#endif
-        default:
-            FatalError("Database flavor not supported\n");
-            return 1;
-    }
-}
 
-int sgBeginTransaction(OpSguil_Data *op_data)
-{
-    switch(op_data->flavor)
+        /* Null out TCP fields */
+        for(i=0; i < 10; i++)
+            Tcl_DStringAppendElement(list, "");
+
+    }
+    else
     {
-#ifdef ENABLE_MYSQL
-        case FLAVOR_MYSQL:
-            return sgMysqlInsert(op_data->mysql, "BEGIN", NULL);
-#endif
-        default:
-            FatalError("Database flavor not supported\n");
-            return 1;
+
+        sprintf(buffer, "%u", p->sp);
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", p->dp);
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", ntohl(p->tcph->th_seq));
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", ntohl(p->tcph->th_ack));
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", TCP_OFFSET(p->tcph));
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", TCP_X2(p->tcph));
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", p->tcph->th_flags);
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", ntohs(p->tcph->th_win));
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", ntohs(p->tcph->th_sum));
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", ntohs(p->tcph->th_urp));
+        Tcl_DStringAppendElement(list, buffer);
+
     }
+
+    /* empty elements for UDP data */
+    for(i=0; i < 2; i++)
+        Tcl_DStringAppendElement(list, "");
+
+    return 0;
+
 }
 
-int sgEndTransaction(OpSguil_Data *op_data)
+int OpSguil_AppendUDPData(Tcl_DString *list, Packet *p)
 {
-    switch(op_data->flavor)
+
+    int i;
+    char buffer[STD_BUFFER];
+
+    bzero(buffer, STD_BUFFER);
+ 
+    /* empty elements for icmp data */
+    for(i=0; i < 5; i++)
+        Tcl_DStringAppendElement(list, "");
+
+    if(!p->udph)
     {
-#ifdef ENABLE_MYSQL
-        case FLAVOR_MYSQL:
-            return sgMysqlInsert(op_data->mysql, "COMMIT", NULL);
-#endif
-        default:
-            FatalError("Database flavor not supported\n");
-            return 1;
+        
+        /* Null out port info */
+        for(i=0; i < 2; i++)
+            Tcl_DStringAppendElement(list, "");
+
     }
-}
-    
-int sgAbortTransaction(OpSguil_Data *op_data)
-{
-    switch(op_data->flavor)
+    else
     {
-#ifdef ENABLE_MYSQL
-        case FLAVOR_MYSQL:
-            return sgMysqlInsert(op_data->mysql, "ROLLBACK", NULL);
-#endif
-        default:
-            FatalError("Database flavor not supported\n");
-            return 1;
+
+        /* source and dst port */
+        sprintf(buffer, "%u", p->sp);
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", p->dp);
+        Tcl_DStringAppendElement(list, buffer);
+
     }
-}
 
+    /* empty elements for tcp data */
+    for(i=0; i < 8; i++)
+        Tcl_DStringAppendElement(list, "");
+
+    if(!p->udph)
+    {
+        
+        /* Null out UDP info */
+        for(i=0; i < 2; i++)
+            Tcl_DStringAppendElement(list, "");
+
+    }
+    else
+    {
+
+        sprintf(buffer, "%u", ntohs(p->udph->uh_len));
+        Tcl_DStringAppendElement(list, buffer);
+
+        sprintf(buffer, "%u", ntohs(p->udph->uh_chk));
+        Tcl_DStringAppendElement(list, buffer);
 
-#ifdef ENABLE_MYSQL
-int sgMysqlConnect(OpSguil_Data *op_data)
-{
-    op_data->mysql = mysql_init(NULL);
-    if(!mysql_real_connect(op_data->mysql, op_data->server, op_data->user, 
-                op_data->password, op_data->database, 0, NULL, 0))
-    {
-        FatalError("Failed to connect to database %s:%s@%s/%s: %s\n",
-                op_data->user, op_data->password, op_data->server, 
-                op_data->database, mysql_error(op_data->mysql));
     }
+
     return 0;
+
 }
 
-int sgMysqlClose(MYSQL *mysql)
+int OpSguil_AppendPayloadData(Tcl_DString *list, Packet *p)
 {
-    mysql_close(mysql);
+
+    char *hex_payload;
+
+    if(p->dsize)
+    {
+        hex_payload = fasthex(p->data, p->dsize);
+        Tcl_DStringAppendElement(list, hex_payload);
+        free(hex_payload);
+    } else {
+        Tcl_DStringAppendElement(list, "");
+    }
+
     return 0;
+
 }
 
-int sgMysqlExecuteQuery(MYSQL *mysql, char *sql)
+
+int OpSguil_SensorAgentConnect(OpSguil_Data *data)
 {
-    int mysqlErrno;
-    int result;
-    while((result = mysql_query(mysql, sql) != 0))
+
+    int sockfd;
+    struct sockaddr_in my_addr;
+
+    while(1)
     {
-        mysqlErrno = mysql_errno(mysql);
-        if(mysqlErrno < CR_MIN_ERROR)
+
+        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
         {
-            if(pv.verbose)
-                LogMessage("MySQL ERROR(%i): %s.  Aborting Query\n",
-                        mysql_errno(mysql), mysql_error(mysql));
-            return result;
+            FatalError("Cannot open a local socket.\n");
+            return 1;
         }
-        if((mysqlErrno == CR_SERVER_LOST) 
-                || (mysqlErrno == CR_SERVER_GONE_ERROR))
+
+        my_addr.sin_family = AF_INET;
+        my_addr.sin_port = htons(data->agent_port);
+        my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
+        memset(&(my_addr.sin_zero), '\0', 8);
+
+    
+        if (connect(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) < 0)
         {
-            LogMessage("Lost connection to MySQL server.  Reconnecting\n");
-            while(mysql_ping(mysql) != 0)
+            LogMessage("Cannot connect to localhost on TCP port %u.\n",
+                        data->agent_port);
+            close(sockfd);
+            LogMessage("Waiting 15 secs to try again.\n");
+            if (BarnyardSleep(15))
             {
-                if(BarnyardSleep(15))
-                    return result;
+                LogMessage("Received Kill Signal...");
+                CleanExit(0);
             }
-            LogMessage("Reconnected to MySQL server.\n");
+
         }
         else
         {
-            /* XXX we could spin here, but we do not */
-            LogMessage("MySQL Error(%i): %s\n", mysqlErrno, mysql_error(mysql));
+
+            data->agent_sock = sockfd;
+            LogMessage("Connected to localhost on %u.\n",
+                        data->agent_port);
+            return 0;
+
         }
+
     }
-    return result;
-}
 
+}
 
-int sgMysqlSelectAsUInt(MYSQL *mysql, char *sql, unsigned int *result)
+/*
+int OpSguil_SensorAgentAuth(OpSguil_Data *data)
 {
-    int rval = 0;
-    MYSQL_RES *mysql_res;
-    MYSQL_ROW tuple;
-    
-    if(sgMysqlExecuteQuery(mysql, sql) != 0)
-    {
-        /* XXX: should really just return up the chain */
-        FatalError("Error (%s) executing query: %s\n", mysql_error(mysql), sql);
-        return -1;
-    }
 
-    mysql_res = mysql_store_result(mysql);
-    if((tuple = mysql_fetch_row(mysql_res)))
-    {
-        if(tuple[0] == NULL)
-            *result = 0;
-        else
-            *result = atoi(tuple[0]);
-        rval = 1;
-    }
-    mysql_free_result(mysql_res);
-    return rval;
+    Tcl_DString auth_cmd;
+
+    Tcl_DStringInit(&auth_cmd);
+    Tcl_DStringAppendElement(auth_cmd, "AUTH");
+    Tcl_DStringAppendElement(auth_cmd, data->passwd);
+    
+    
 }
+*/
 
-int sgMysqlInsert(MYSQL *mysql, char *sql, unsigned int *row_id)
+/* Request sensor ID (sid) and next cid from sensor_agent */
+int OpSguil_SensorAgentInit(OpSguil_Data *data)
 {
-    if(sgMysqlExecuteQuery(mysql, sql) != 0)
+
+    char tmpSendMsg[MAX_MSG_LEN];
+    char tmpRecvMsg[MAX_MSG_LEN];
+
+    /* Send our Request */
+    snprintf(tmpSendMsg, MAX_MSG_LEN, "SidCidRequest %s", data->sensor_name);
+    OpSguil_SendAgentMsg(data, tmpSendMsg);
+
+    /* Get the Results */
+    memset(tmpRecvMsg,0x0,MAX_MSG_LEN);
+    if(OpSguil_RecvAgentMsg(data, tmpRecvMsg) == 1 )
     {
-        /* XXX: should really just return up the chain */
-        FatalError("Error (%s) executing query: %s\n", mysql_error(mysql), sql);
-        return -1;
+
+        OpSguil_SensorAgentInit(data);
+
     }
+    else
+    {
 
-    if(row_id != NULL)
-        *row_id = mysql_insert_id(mysql);
-    return 0;
-}
-#endif
+        char **toks;
+        int num_toks;
 
-/* SguildConnect() opens a network socket to sguild for sending
- * RT event messages.  Bammkkkk
-*/
-int SguildConnect(OpSguil_Data *op_data)
-{
-	int sockfd;
-	struct hostent *he;
-	struct sockaddr_in server_addr;
+        if(pv.verbose)
+            LogMessage("Received: %s", tmpRecvMsg);
 
-	if ((he=gethostbyname(op_data->sguild_host)) == NULL)
+        /* Parse the response */
+        toks = mSplit(tmpRecvMsg, " ", 3, &num_toks, 0);
+        if(strcasecmp("SidCidResponse", toks[0]) == 0)
         {
-                FatalError("Cannot resolve hostname: %s\n", op_data->sguild_host);
-                return 1;
+
+            data->sensor_id = atoi(toks[1]);
+            data->event_id = atoi(toks[2]);
+
         }
-        
-        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
+        else
         {
- 
-            FatalError("Cannot open a local socket.\n");
-            return 1;
- 
+
+            FatalError("Expected SidCidResponse and got: %s\n", tmpRecvMsg);
+
         }
 
-        server_addr.sin_family = AF_INET;
-        server_addr.sin_port = htons(op_data->sguild_port);
-        server_addr.sin_addr = *((struct in_addr *)he->h_addr);
-        memset(&(server_addr.sin_zero), '\0', 8);
+        FreeToks(toks, num_toks);
 
-        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0)
-        {
-                                                                                                              
-           LogMessage("Cannot connect to %s on TCP port %u.\n",
-                op_data->sguild_host, op_data->sguild_port);
-           close(sockfd);
-           return 1;
+        if(pv.verbose)
+         LogMessage("Sensor ID: %u\nLast cid: %u\n", data->sensor_id, data->event_id);
+
+        /* Use the next event_id */
+        ++data->event_id;
+
+    }
+
+    return 0;
+
+}
+
+int OpSguil_SendAgentMsg(OpSguil_Data *data, char *msg)
+{
+
+    int schars;
+    size_t len;
+    char *tmpMsg;
+
+    len = strlen(msg)+2;
 
-        } 
+    tmpMsg = SafeAlloc(len);
 
-        op_data->sguild_sock = sockfd;
-        return 0;
+    snprintf(tmpMsg, len, "%s\n", msg);
+
+    if((schars = send(data->agent_sock, tmpMsg, sizeof(char)*strlen(tmpMsg), 0)) < 0)
+    {
+
+        if(pv.verbose)
+         LogMessage("Lost connection to sensor_agent.\n");
+
+        /* Resend our msg */
+        OpSguil_SendAgentMsg(data, msg);
+
+    }
+
+    if(pv.verbose)
+     LogMessage("Sent: %s", tmpMsg);
+
+    free(tmpMsg);
+
+    return 0;
 
 }
+
 /* I love google. http://pont.net/socket/prog/tcpServer.c */
-int read_line(int newSd, char *line_to_return) {
-  
+int OpSguil_RecvAgentMsg(OpSguil_Data *data, char *line_to_return) {
+                                                                                                                                    
   static int rcv_ptr=0;
   static char rcv_msg[MAX_MSG_LEN];
   static int n;
+  struct timeval tv;
+  fd_set read_fds;
   int offset;
-
+                                                                                                                                    
   offset=0;
+  /* wait 15 secs for our response */
+  tv.tv_sec = 15;
+  tv.tv_usec = 0;
+
+  FD_ZERO(&read_fds);
+  FD_SET(data->agent_sock, &read_fds);
 
   while(1) {
-    if(rcv_ptr==0) {
 
-      memset(rcv_msg,0x0,MAX_MSG_LEN);
-      n = recv(newSd, rcv_msg, MAX_MSG_LEN, 0);
-      if (n<0) {
-	LogMessage("ERROR: Unable to read data.\n");
-	return 1;
-      } else if (n==0) {
-	LogMessage("ERROR: Connecton closed by client\n");
-	close(newSd);
-	return 1;
-      }
+    /* Wait for response from sguild */
+    select(data->agent_sock+1, &read_fds, NULL, NULL, &tv);
+                                                                                                                                    
+    if (!(FD_ISSET(data->agent_sock, &read_fds)))
+    {
+        /* timed out */
+        if(pv.verbose)
+         LogMessage("Timed out waiting for response.\n");
+
+        return 1;
     }
+    else
+    {
+      if(rcv_ptr==0) {
+                                                                                                                                    
+        memset(rcv_msg,0x0,MAX_MSG_LEN);
+        n = recv(data->agent_sock, rcv_msg, MAX_MSG_LEN, 0);
+        if (n<0) {
+          LogMessage("ERROR: Unable to read data.\n");
+          /* Reconnect to sensor_agent */
+          OpSguil_SensorAgentConnect(data);
+        } else if (n==0) {
+          LogMessage("ERROR: Connecton closed by client\n");
+          close(data->agent_sock);
+          /* Reconnect to sensor_agent */
+          OpSguil_SensorAgentConnect(data);
+        }
+      }
+                                                                                                                                    
+      /* if new data read on socket */
+      /* OR */
+      /* if another line is still in buffer */
+                                                                                                                                    
+      /* copy line into 'line_to_return' */
+      while(*(rcv_msg+rcv_ptr)!=0x0A && rcv_ptr<n) {
+        memcpy(line_to_return+offset,rcv_msg+rcv_ptr,1);
+        offset++;
+        rcv_ptr++;
+      }
+                                                                                                                                      
+      /* end of line + end of buffer => return line */
+      if(rcv_ptr==n-1) {
+        /* set last byte to END_LINE */
+        *(line_to_return+offset)=0x0A;
+        rcv_ptr=0;
+        return ++offset;
+      }
+
+      /* end of line but still some data in buffer => return line */
+      if(rcv_ptr <n-1) {
+        /* set last byte to END_LINE */
+        *(line_to_return+offset)=0x0A;
+        rcv_ptr++;
+        return ++offset;
+      }
   
-    /* if new data read on socket */
-    /* OR */
-    /* if another line is still in buffer */
-
-    /* copy line into 'line_to_return' */
-    while(*(rcv_msg+rcv_ptr)!=0x0A && rcv_ptr<n) {
-      memcpy(line_to_return+offset,rcv_msg+rcv_ptr,1);
-      offset++;
-      rcv_ptr++;
-    }
-    
-    /* end of line + end of buffer => return line */
-    if(rcv_ptr==n-1) { 
-      /* set last byte to END_LINE */
-      *(line_to_return+offset)=0x0A;
-      rcv_ptr=0;
-      return ++offset;
-    } 
-    
-    /* end of line but still some data in buffer => return line */
-    if(rcv_ptr <n-1) {
-      /* set last byte to END_LINE */
-      *(line_to_return+offset)=0x0A;
-      rcv_ptr++;
-      return ++offset;
+      /* end of buffer but line is not ended => */
+      /*  wait for more data to arrive on socket */
+      if(rcv_ptr == n) {
+        rcv_ptr = 0;
+      }
+
     }
 
-    /* end of buffer but line is not ended => */
-    /*  wait for more data to arrive on socket */
-    if(rcv_ptr == n) {
-      rcv_ptr = 0;
-    } 
-    
   }
-}
 
-/* SguilSendEvent() sends the event via the open network socket.
- * Bammkkkk
-*/
-int SguilSendEvent(OpSguil_Data *op_data, char *eventMsg)
-{
-
-     int schars;
-     char line[100];
-     
-
-     if((schars = send(op_data->sguild_sock, eventMsg, strlen(eventMsg), 0)) < 0)
-     {
-             LogMessage("ERROR! Couldn't send msg.\n");
-
-             /* ReConnect to sguild */
-             while(SguildConnect(op_data) == 1)
-             {
-                 if(op_data->nospin) return 0;
-                 LogMessage("ERROR: Couldn't reconnect. Will try again in 15 secs.\n");
-                 if (BarnyardSleep(15)) break;
-             }
-             LogMessage("Connected to %s.\n", op_data->sguild_host);
-             SguilSendEvent(op_data, eventMsg);
-
-     } else {
-
-             //LogMessage("Msg sent: %s", eventMsg);
-             //LogMessage("Chars sent: %i\n", schars);
-
-             memset(line, 0x0, 100);
-             if(read_line(op_data->sguild_sock, line) == 1)
-             {
-
-                 if (op_data->nospin == 0)
-                 {
-
-
-                    LogMessage("ERROR! Didn't receive confirmation. Trying to reconnect.\n");
-
-                    /* ReConnect to sguild */
-                    while(SguildConnect(op_data) == 1)
-                    {
-                        LogMessage("ERROR: Couldn't reconnect. Will try again in 15 secs.\n");
-                        if (BarnyardSleep(15)) break;
-                    }
- 
-                    LogMessage("Connected to %s.\n", op_data->sguild_host);
-                    SguilSendEvent(op_data, eventMsg);
-
-                 }
-
-             }
-     }
-     return 0;
-     
 }
 
-#endif
