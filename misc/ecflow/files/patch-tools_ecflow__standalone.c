--- tools/ecflow_standalone.c.orig	2022-08-25 05:28:39 UTC
+++ tools/ecflow_standalone.c
@@ -183,7 +183,7 @@ int main(argc,argv) int argc; char **argv;
      for (n=3; n<65535 ;n++) fclose(n); */
 
   /* create a new session from the child process */
-#if defined(linux) || defined(__APPLE__) || defined(__MACH__) || defined(hpux) || defined(solaris) || defined(SGI) || defined(SVR4) || defined(AIX) || defined(SYG) || defined(alpha)
+#if defined(linux) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__MACH__) || defined(hpux) || defined(solaris) || defined(SGI) || defined(SVR4) || defined(AIX) || defined(SYG) || defined(alpha)
   if( setsid() == -1 )
 #else
   if( setsid(0) == -1 )
