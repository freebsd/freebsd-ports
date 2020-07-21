--- makefiles/Makefile.dotnet.mk.orig	2020-06-12 13:05:43 UTC
+++ makefiles/Makefile.dotnet.mk
@@ -62,7 +62,11 @@ else
     ifeq ($(OS),Darwin)
     RUNTIME_IDENTIFIER=osx-x64
     else
-    $(error OS unknown !)
+      ifeq ($(OS),FreeBSD)
+      RUNTIME_IDENTIFIER=freebsd-amd64
+      else
+        $(error OS unknown !)
+      endif
     endif
   endif
 endif
