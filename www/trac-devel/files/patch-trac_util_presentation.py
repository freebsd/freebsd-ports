--- trac/util/presentation.py.orig	2021-05-09 23:08:49 UTC
+++ trac/util/presentation.py
@@ -21,13 +21,13 @@ from datetime import datetime
 from math import ceil
 import re
 
-from jinja2 import Markup, Undefined, contextfilter, evalcontextfilter
+from jinja2 import Undefined, contextfilter, evalcontextfilter
 from jinja2.filters import make_attrgetter
-from jinja2.utils import soft_unicode
 
 from trac.core import TracError
 from .datefmt import to_utimestamp, utc
-from .html import Fragment, classes, html_attribute, styles, tag
+from .html import (Fragment, Markup, classes, html_attribute, soft_unicode,
+                   styles, tag)
 from .text import javascript_quote
 
 __all__ = ['captioned_button', 'classes', 'first_last', 'group', 'istext',
