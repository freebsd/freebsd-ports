--- includes/MagicWord.php.orig	2014-02-12 22:03:25.000000000 +0800
+++ includes/MagicWord.php	2014-02-12 22:05:10.000000000 +0800
@@ -704,7 +704,9 @@
 				$magic = MagicWord::get( $name );
 				$case = intval( $magic->isCaseSensitive() );
 				foreach ( $magic->getSynonyms() as $i => $syn ) {
-					$group = "(?P<{$i}_{$name}>" . preg_quote( $syn, '/' ) . ')';
+					// Group name must start with a non-digit in PCRE 8.34+
+					$it = strtr( $i, '0123456789', 'abcdefghij' );
+					$group = "(?P<{$it}_{$name}>" . preg_quote( $syn, '/' ) . ')';
 					if ( $this->baseRegex[$case] === '' ) {
 						$this->baseRegex[$case] = $group;
 					} else {
