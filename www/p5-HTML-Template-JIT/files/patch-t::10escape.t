--- t/10escape.t	Tue May 18 18:39:12 2004
+++ t/10escape.t	Tue May 18 18:42:03 2004
@@ -1,4 +1,4 @@
-use Test::More tests => 3;
+use Test::More tests => 4;
 use HTML::Template::JIT;
 my $debug = 0;
 
@@ -35,3 +35,13 @@
 $output = $template->output;
 like($output, qr/Some URL escaped stuff:/); 
 
+# test 8bit char in urlescaped var
+$template = HTML::Template::JIT->new(
+                                     filename => 'urlescape.tmpl',
+                                     path => ['t/templates'],
+                                     jit_path => 't/jit_path',
+                                     jit_debug => $debug,
+                                    );
+$template->param(STUFF => "\xf4"); #"
+$output = $template->output;
+like($output, qr/%F4/); #"
