--- Makefile.PL.orig	2025-03-19 14:58:34 UTC
+++ Makefile.PL
@@ -255,7 +255,7 @@
 		 ) :
 		 (MYEXTLIB   =>  'libPARI/libPARI$(LIB_EXT)')),
 		  LIBS	     =>  $libs,
-		  INC	     =>  $extra_inc . ' -I $(PARI_DIR_SRC)/headers -I $(PARI_DIR_SRC) -I ./libPARI',
+		  INC	     =>  '-I$(PARI_DIR)/src',
 	       VERSION_FROM  => 'Pari.pm',
     ($] >= 5.005 ?     ## Add these new keywords supported since 5.005
       (ABSTRACT_FROM  => 'Pari.pm', # retrieve abstract from module
