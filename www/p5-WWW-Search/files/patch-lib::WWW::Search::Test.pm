--- lib/WWW/Search/Test.pm~	Tue Jul 15 05:02:28 2003
+++ lib/WWW/Search/Test.pm	Thu Aug  7 15:18:31 2003
@@ -627,7 +627,7 @@
       print $oResult->url, "\n";
       foreach my $sField (qw( title description score change_date index_date size company location source ))
         {
-        print "  $sField==", $oResult->$sField, "==\n" if defined($oResult->$sField);
+        print "  $sField==", eval "$oResult->$sField", "==\n" if $oResult->can($sField);
         } # foreach
       } # foreach
     } # if
