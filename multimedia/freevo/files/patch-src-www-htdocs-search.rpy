--- src/www/htdocs/search.rpy.orig	2009-02-19 12:59:44.000000000 -0500
+++ src/www/htdocs/search.rpy	2010-04-19 20:03:02.000000000 -0400
@@ -113,17 +113,17 @@
                 if not chan: chan = 'UNKNOWN'
                 fv.tableCell(chan, 'class="'+status+'" colspan="1"')
 
-                fv.tableCell(prog.title, 'class="'+status+'" colspan="1"')
+                fv.tableCell(unicode(prog.title, 'iso-8859-1'), 'class="'+status+'" colspan="1"')
                 if prog.sub_title:
-                    fv.tableCell(prog.sub_title, 'class="'+status+'" colspan="1"')
+                    fv.tableCell(unicode(prog.sub_title, 'iso-8859-1'), 'class="'+status+'" colspan="1"')
                 else:
                     fv.tableCell('&nbsp;', 'class="'+status+'" colspan="1"')
 
 
                 if prog.desc == '':
-                    cell = _('Sorry, the program description for %s is unavailable.') % ('<b>'+prog.title+'</b>')
+                    cell = _('Sorry, the program description for %s is unavailable.') % ('<b>'+unicode(prog.title, 'iso-8859-1')+'</b>')
                 else:
-                    cell = prog.desc
+                    cell = unicode(prog.desc, 'iso-8859-1')
                 fv.tableCell(cell, 'class="'+status+'" colspan="1"')
 
                 if status == 'scheduled':
