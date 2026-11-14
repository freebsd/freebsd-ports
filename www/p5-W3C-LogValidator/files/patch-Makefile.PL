--- Makefile.PL.orig	2017-08-24 10:47:40 UTC
+++ Makefile.PL
@@ -23,6 +23,17 @@ WriteMakefile(
 			     'DB_File' => 0,
 			     'Mail::Sendmail' => 0,
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
