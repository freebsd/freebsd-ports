--- g10/keygen.c.orig	Tue Jul 29 03:34:41 2003
+++ g10/keygen.c	Thu Nov 27 18:54:55 2003
@@ -958,8 +958,6 @@
     tty_printf(    _("   (%d) DSA (sign only)\n"), 2 );
     if( addmode )
 	tty_printf(    _("   (%d) ElGamal (encrypt only)\n"), 3 );
-    if (opt.expert)
-        tty_printf(    _("   (%d) ElGamal (sign and encrypt)\n"), 4 );
     tty_printf(    _("   (%d) RSA (sign only)\n"), 5 );
     if (addmode)
         tty_printf(    _("   (%d) RSA (encrypt only)\n"), 6 );
@@ -989,21 +987,6 @@
 	    algo = PUBKEY_ALGO_RSA;
             *r_usage = PUBKEY_USAGE_SIG;
 	    break;
-	}
-	else if( algo == 4 && opt.expert)
-	  {
-	    tty_printf(_(
-"The use of this algorithm is only supported by GnuPG.  You will not be\n"
-"able to use this key to communicate with PGP users.  This algorithm is also\n"
-"very slow, and may not be as secure as the other choices.\n"));
-
-	    if( cpr_get_answer_is_yes("keygen.algo.elg_se",
-				      _("Create anyway? ")))
-	      {
-		algo = PUBKEY_ALGO_ELGAMAL;
-		*r_usage = PUBKEY_USAGE_ENC | PUBKEY_USAGE_SIG;
-		break;
-	      }
 	}
 	else if( algo == 3 && addmode ) {
 	    algo = PUBKEY_ALGO_ELGAMAL_E;
