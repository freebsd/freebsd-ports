--- UFconfig/UFconfig.mk.orig	2011-07-19 19:43:11.000000000 -0400
+++ UFconfig/UFconfig.mk	2011-07-19 19:44:13.000000000 -0400
@@ -237,18 +237,18 @@
 
 # alternatives:
 # CFLAGS = -g -fexceptions \
-   	-Wall -W -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
-    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi \
-        -funit-at-a-time
+#   	-Wall -W -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
+#    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi \
+#       -funit-at-a-time
 # CFLAGS = -O3 -fexceptions \
-   	-Wall -W -Werror -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
-    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
+#   	-Wall -W -Werror -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
+#    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
 # CFLAGS = -O3 -fexceptions -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE
 # CFLAGS = -O3
 # CFLAGS = -O3 -g -fexceptions
 # CFLAGS = -g -fexceptions \
-   	-Wall -W -Wshadow \
-    	-Wredundant-decls -Wdisabled-optimization -ansi
+#   	-Wall -W -Wshadow \
+#    	-Wredundant-decls -Wdisabled-optimization -ansi
 
 # consider:
 # -fforce-addr -fmove-all-movables -freduce-all-givs -ftsp-ordering
