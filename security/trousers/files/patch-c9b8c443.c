commit c9b8c4434f3b11bae4f7e72c3aec5b4f3459eecc
Author: Jerry Snitselaar <jsnitsel@redhat.com>
Date:   Wed Mar 18 14:10:35 2020 -0700

    trousers: resolve build failure
    
    The global variables tcsd_sa_chld and tcsd_sa_int in tcsd.h are
    causing build failures in latest Fedora release:
    
    /usr/bin/ld: ../../src/tcs/libtcs.a(libtcs_a-tcsi_changeauth.o):/builddir/build/BUILD/trousers-0.3.13/src/tcs/../include/tcsd.h:169: multiple definition of `tcsd_sa_chld'; tcsd-svrside.o:/builddir/build/BUILD/trousers-0.3.13/src/tcsd/../../src/include/tcsd.h:169: first defined here
    /usr/bin/ld: ../../src/tcs/libtcs.a(libtcs_a-tcsi_changeauth.o):/builddir/build/BUILD/trousers-0.3.13/src/tcs/../include/tcsd.h:168: multiple definition of `tcsd_sa_int'; tcsd-svrside.o:/builddir/build/BUILD/trousers-0.3.13/src/tcsd/../../src/include/tcsd.h:168: first defined here
    
    They are no longer used since 9b40e581470b ("Improved daemon's signal
    handling") so just remove them.
    
    Signed-off-by: Jerry Snitselaar <jsnitsel@redhat.com>
    Signed-off-by: Debora Velarde Babb <debora@linux.ibm.com>

diff --git src/include/tcsd.h src/include/tcsd.h
index 5b9462b..f5c286e 100644
--- src/include/tcsd.h
+++ src/include/tcsd.h
@@ -164,10 +164,4 @@ TSS_RESULT tcsd_thread_create(int, char *);
 void	   *tcsd_thread_run(void *);
 void	   thread_signal_init();
 
-/* signal handling */
-#ifndef __APPLE__
-struct sigaction tcsd_sa_int;
-struct sigaction tcsd_sa_chld;
-#endif
-
 #endif
