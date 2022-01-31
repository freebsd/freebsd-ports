--- liboath/tests/tst_totp_validate.c.orig	2022-01-31 11:03:27 UTC
+++ liboath/tests/tst_totp_validate.c
@@ -156,7 +156,7 @@ main (void)
 	}
       if (otp_counter != tv[i].otp_counter)
 	{
-	  printf ("validate3 loop %ld failed (counter %d != %d)?!\n",
+	  printf ("validate3 loop %ld failed (counter %ld != %ld)?!\n",
 		  i, otp_counter, tv[i].otp_counter);
 	  return 1;
 	}
@@ -184,7 +184,7 @@ main (void)
 	}
       if (otp_counter != tv[i].otp_counter)
 	{
-	  printf ("validate3_callback loop %ld failed (counter %d != %d)?!\n",
+	  printf ("validate3_callback loop %ld failed (counter %ld != %ld)?!\n",
 		  i, otp_counter, tv[i].otp_counter);
 	  return 1;
 	}
