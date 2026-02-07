--- Makefile.PL.orig	Thu Feb 10 18:57:36 2005
+++ Makefile.PL	Thu Feb 10 19:10:24 2005
@@ -24,6 +24,17 @@
 			     'Mail::Sendmail' => 0,
 			     'WebService::Validator::CSS::W3C' => 0
                            },
+   'MAN3PODS'		=> {
+			     'lib/W3C/LogValidator.pm' => 'blib/man3/W3C::LogValidator.3',
+			     'lib/W3C/LogValidator/Basic.pm' => 'blib/man3/W3C::LogValidator::Basic.3',
+			     'lib/W3C/LogValidator/Config.pm' => 'blib/man3/W3C::LogValidator::Config.3',
+			     'lib/W3C/LogValidator/CSSValidator.pm' => 'blib/man3/W3C::LogValidator::CSSValidator.3',
+			     'lib/W3C/LogValidator/HTMLValidator.pm' => 'blib/man3/W3C::LogValidator::HTMLValidator.3',
+			     'lib/W3C/LogValidator/Output/HTML.pm' => 'blib/man3/W3C::LogValidator::Output::HTML.3',
+			     'lib/W3C/LogValidator/Output/Mail.pm' => 'blib/man3/W3C::LogValidator::Output::Mail.3',
+			     'lib/W3C/LogValidator/Output/Raw.pm' => 'blib/man3/W3C::LogValidator::Output::Raw.3',
+			     'lib/W3C/LogValidator/SurveyEngine.pm' => 'blib/man3/W3C::LogValidator::SurveyEngine.3',
+			   },
     'EXE_FILES'         => [ 'bin/logprocess.pl' ],
     'dist'              => { COMPRESS => 'gzip -9f', SUFFIX => '.gz' },
 );
