--- lib/Mail/SpamAssassin/Conf.pm	(revision 903394)
+++ lib/Mail/SpamAssassin/Conf.pm	(working copy)
@@ -2156,8 +2156,8 @@
 =item header SYMBOLIC_TEST_NAME exists:name_of_header
 
 Define a header existence test.  C<name_of_header> is the name of a
-header to test for existence.  This is just a very simple version of
-the above header tests.
+header field to test for existence.  This is just a very simple version
+of the above header tests.
 
 =item header SYMBOLIC_TEST_NAME eval:name_of_eval_method([arguments])
 
@@ -2280,7 +2280,8 @@
           $self->{parser}->add_test ($name, $fn, $TYPE_HEAD_EVALS);
         }
       }
-      elsif ($value =~ /^(\S+)\s+exists:(.*)$/) {
+      elsif ($value =~ /^(\S+)\s+exists:([!-9;-\176]+)$/) {
+        # RFC 5322 section 3.6.8, ftext printable US-ASCII ch not including ":"
         $self->{parser}->add_test ($1, "defined($2)", $TYPE_HEAD_TESTS);
         $self->{descriptions}->{$1} = "Found a $2 header";
       }

