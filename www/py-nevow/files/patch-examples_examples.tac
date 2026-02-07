--- examples/examples.tac.orig	2015-08-11 22:04:11 UTC
	+++ examples/examples.tac
	@@ -7,13 +7,6 @@ to run Nevow """
	     import sys
	     sys.exit(1)
	 
	-
	-from twisted.python import components
	-import warnings
	-warnings.filterwarnings(
	-    'ignore',
	-    category=components.ComponentsDeprecationWarning)
	-
	 from twisted.application import service, strports
	 from twisted.python import util
	
