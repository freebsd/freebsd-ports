--- doc/pgsql-db-script.sql.orig	2024-04-04 09:13:29 UTC
+++ doc/pgsql-db-script.sql
@@ -24,7 +24,7 @@ SET search_path = exilog, pg_catalog;
 
 CREATE TABLE deferrals (
     server character varying(32) NOT NULL,
-    message_id character(16) NOT NULL,
+    message_id character(23) NOT NULL,
     "timestamp" bigint NOT NULL,
     rcpt character varying(200) NOT NULL,
     rcpt_intermediate character varying(200),
@@ -46,7 +46,7 @@ CREATE TABLE deferrals (
 
 CREATE TABLE errors (
     server character varying(32) NOT NULL,
-    message_id character(16) NOT NULL,
+    message_id character(23) NOT NULL,
     "timestamp" bigint NOT NULL,
     rcpt character varying(200) NOT NULL,
     rcpt_intermediate character varying(200),
@@ -68,7 +68,7 @@ CREATE TABLE errors (
 
 CREATE TABLE deliveries (
     server character varying(32) NOT NULL,
-    message_id character(16) NOT NULL,
+    message_id character(23) NOT NULL,
     "timestamp" bigint NOT NULL,
     rcpt character varying(200) NOT NULL,
     rcpt_intermediate character varying(200),
@@ -89,7 +89,7 @@ CREATE TABLE deliveries (
 
 CREATE TABLE queue (
     server character varying(32) NOT NULL,
-    message_id character(16) NOT NULL,
+    message_id character(23) NOT NULL,
     mailfrom character varying(255),
     "timestamp" bigint,
     num_dsn integer,
@@ -111,7 +111,7 @@ CREATE TABLE queue (
 
 CREATE TABLE "unknown" (
     server character varying(32) NOT NULL,
-    message_id character(16) NOT NULL,
+    message_id character(23) NOT NULL,
     "timestamp" bigint NOT NULL,
     line character varying(255) NOT NULL
 );
@@ -124,7 +124,7 @@ CREATE TABLE "unknown" (
 
 CREATE TABLE messages (
     server character varying(32) NOT NULL,
-    message_id character(16) NOT NULL,
+    message_id character(23) NOT NULL,
     "timestamp" bigint,
     msgid character varying(255),
     completed bigint,
@@ -148,7 +148,7 @@ CREATE TABLE messages (
 
 CREATE TABLE rejects (
     server character varying(32) NOT NULL,
-    message_id character(16),
+    message_id character(23),
     "timestamp" bigint NOT NULL,
     host_addr inet,
     host_rdns character varying(255),
