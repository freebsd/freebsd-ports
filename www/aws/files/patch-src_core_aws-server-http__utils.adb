Current_Process_Id is not available on GCC 6.x

--- src/core/aws-server-http_utils.adb.orig	2016-09-28 15:14:26 UTC
+++ src/core/aws-server-http_utils.adb
@@ -39,7 +39,6 @@ with Ada.Strings.Unbounded;
 with Ada.Text_IO;
 
 with GNAT.MD5;
-with GNAT.OS_Lib;
 with GNAT.Regexp;
 
 with AWS.Attachments;
@@ -924,8 +923,7 @@ package body AWS.Server.HTTP_Utils is
 
       function Get_File_Upload_UID return String is
          use GNAT;
-         Pid : constant Natural := Integer'Max
-                 (0, OS_Lib.Pid_To_Integer (OS_Lib.Current_Process_Id));
+         Pid : constant Natural := 0;
          --  On OS where Current_Process_Id is not support -1 is returned. We
          --  ensure that in this case the Pid is set to 0 in this case.
          UID : Natural;
