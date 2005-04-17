
$FreeBSD$

--- stun.cxx
+++ stun.cxx
@@ -648,55 +648,13 @@
 stunRand()
 {
    // return 32 bits of random stuff
-   assert( sizeof(int) == 4 );
    static bool init=false;
-   if ( !init )
-   { 
+   if ( !init ) {
+      srandomdev();
       init = true;
-		
-      UInt64 tick;
-		
-#if defined(WIN32) 
-      volatile unsigned int lowtick=0,hightick=0;
-      __asm
-         {
-            rdtsc 
-               mov lowtick, eax
-               mov hightick, edx
-               }
-      tick = hightick;
-      tick <<= 32;
-      tick |= lowtick;
-#elif defined(__GNUC__) && ( defined(__i686__) || defined(__i386__) )
-      asm("rdtsc" : "=A" (tick));
-#elif defined (__SUNPRO_CC) || defined( __sparc__ )	
-      tick = gethrtime();
-#elif defined(__MACH__) 
-      int fd=open("/dev/random",O_RDONLY);
-      read(fd,&tick,sizeof(tick));
-      closesocket(fd);
-#else
-#     error Need some way to seed the random number generator 
-#endif 
-      int seed = int(tick);
-#ifdef WIN32
-      srand(seed);
-#else
-      srandom(seed);
-#endif
    }
-	
-#ifdef WIN32
-   assert( RAND_MAX == 0x7fff );
-   int r1 = rand();
-   int r2 = rand();
-	
-   int ret = (r1<<16) + r2;
-	
-   return ret;
-#else
-   return random(); 
-#endif
+   /* random() is described as returning 0...2**31-1 */
+   return 0xffffffff & ( ( random() << 31 ) | random() );
 }
 
 
