--- includes/OutputPage.php.orig	2011-01-06 10:46:14.000000000 +0800
+++ includes/OutputPage.php	2011-01-06 10:47:53.000000000 +0800
@@ -957,6 +957,9 @@
 		$wgRequest->response()->header( "Content-type: $wgMimeType; charset={$wgOutputEncoding}" );
 		$wgRequest->response()->header( 'Content-language: '.$wgContLanguageCode );
 
+		# To prevent clickjacking, do not allow this page to be inside a frame.
+		$wgRequest->response()->header( 'X-Frame-Options: DENY' );
+
 		if ($this->mArticleBodyOnly) {
 			$this->out($this->mBodytext);
 		} else {
