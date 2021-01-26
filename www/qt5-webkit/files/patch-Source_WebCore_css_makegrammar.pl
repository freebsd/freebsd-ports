Obtained from:	https://github.com/qtwebkit/qtwebkit/commit/d92b11fea65364fefa700249bd3340e0cd4c5b31

--- Source/WebCore/css/makegrammar.pl.orig	2020-03-04 17:16:37 UTC
+++ Source/WebCore/css/makegrammar.pl
@@ -73,25 +73,6 @@ if ($suffix eq ".y.in") {
 }
 
 my $fileBase = File::Spec->join($outputDir, $filename);
-my @bisonCommand = ($bison, "-d", "-p", $symbolsPrefix, $grammarFilePath, "-o", "$fileBase.cpp");
+my @bisonCommand = ($bison, "--defines=$fileBase.h", "-p", $symbolsPrefix, $grammarFilePath, "-o", "$fileBase.cpp");
 push @bisonCommand, "--no-lines" if $^O eq "MSWin32"; # Work around bug in bison >= 3.0 on Windows where it puts backslashes into #line directives.
 system(@bisonCommand) == 0 or die;
-
-open HEADER, ">$fileBase.h" or die;
-print HEADER << "EOF";
-#ifndef CSSGRAMMAR_H
-#define CSSGRAMMAR_H
-EOF
-
-open HPP, "<$fileBase.cpp.h" or open HPP, "<$fileBase.hpp" or die;
-while (<HPP>) {
-    print HEADER;
-}
-close HPP;
-
-print HEADER "#endif\n";
-close HEADER;
-
-unlink("$fileBase.cpp.h");
-unlink("$fileBase.hpp");
-
