--- Bio/Alignment/Bowtie.hs.orig	2013-07-20 07:25:31 UTC
+++ Bio/Alignment/Bowtie.hs
@@ -1,3 +1,4 @@
+{-# LANGUAGE FlexibleContexts #-}
 {-| This module provides a data type to represent an alignment
 produced by the Bowtie short-read alignment tool (see
 <http://bowtie-bio.sourceforge.net/index.shtml>).
