
$FreeBSD$

--- scripts/yaws.ss.orig	Sun Jan 25 16:09:24 2004
+++ scripts/yaws.ss	Sun Jan 25 16:10:26 2004
@@ -1,7 +1,7 @@
 #!/bin/sh
 
 
-yawsdir="%yawsdir%"
+yawsdir="!!PREFIX!!/lib/yaws"
 erl="%erl%"
 case `uname` in
     CYGWIN*)
