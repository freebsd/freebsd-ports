--- t/03loops.t	Wed Jun  9 15:57:13 2004
+++ t/03loops.t	Wed Jun  9 16:00:15 2004
@@ -1,4 +1,4 @@
-use Test::More tests => 8;
+use Test::More tests => 9;
 use HTML::Template::JIT;
 
 my $debug = 0;
@@ -69,3 +69,13 @@
 like($output, qr/Apples, Oranges, Brains, Toes, and Kiwi./);
 like($output, qr/pingpongpingpongpingpong/);
 
+$template = HTML::Template::JIT->new(filename => 'loop.tmpl',
+				     path => ['t/templates'],
+				     jit_path => 't/jit_path',
+				     jit_debug => $debug,
+				    );
+$template->param(foo => "FOO");
+$template->param(bar => [ bless({ val => 'foo' }, 'barfoo'),
+    bless({ val => 'bar' }, 'barbar') ]);
+$output = $template->output();
+like($output, qr/bar: foo,bar,/);
