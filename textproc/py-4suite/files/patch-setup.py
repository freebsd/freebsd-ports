This patch accomplishes the following:

- Force 4Suite NOT to install the included PyXML.  (Instead, the port has a
  dependency on the PyXML port, textproc/py-xml.)

- Eliminate the possibly conflicting installation of 4DOM.  Since PyXML
  0.6.4, 4DOM is maintained as part of that package instead.  (However,
  retain the installation of some of the L10n extensions to 4DOM - the ones
  which are not installed by PyXML.)

- Install (optional) documentation to a path that conforms to FreeBSD's
  hier(7) (but still obey ${PREFIX}).

-- Johann Visagie <johann@egenetics.com>


--- setup.py.orig	Sun Feb 18 23:35:50 2001
+++ setup.py	Tue Mar 20 13:08:39 2001
@@ -53,12 +53,12 @@
 #
 ############################################################
 
-pyxml_install_attempted = 0
-pyxml_install_completed = 0
+pyxml_install_attempted = 1
+pyxml_install_completed = 1
 pyxml_expat = 0
 
-if os.access('PyXML', os.F_OK):
-#if 0:
+#if os.access('PyXML', os.F_OK):
+if 0:
     pyxml_install_attempted = 1
 
     # Rename xml to _xmlplus for Python 2.0
@@ -326,7 +326,6 @@
     # Not really .py files, but go to the same place
     l10n.extend([('Ft.Lib', 'Lib', glob.glob('Lib/*.po'), ['Lib/MessageSource.py']),
                  ('Ft.Rdf', 'Rdf', glob.glob('Rdf/*.po'), ['Rdf/MessageSource.py']),
-                 (xml('dom'), 'Dom', glob.glob('Dom/*.po'), ['Dom/MessageSource.py']),
                  (xml('xpath'), 'XPath', glob.glob('XPath/*.po'), ['XPath/XPathParserBase.py']),
                  ('Ft.XPointer', 'XPointer', glob.glob('XPointer/*.po'), ['XPointer/XPointerParserBase.py']),
                  (xml('xslt'), 'Xslt', glob.glob('Xslt/*.po'), ['Xslt/MessageSource.py', 'Xslt/XPatternParserBase.py']),
@@ -334,6 +333,7 @@
                  ('Ft.Ods.Parsers.Oif', 'Ods/Parsers/Oif', glob.glob('Ods/Parsers/Oif/*.po'), ['Ods/Parsers/Oif/OifParserBase.py']),
                  ('Ft.Ods.Parsers.Oql', 'Ods/Parsers/Oql', glob.glob('Ods/Parsers/Oql/*.po'), ['Ods/Parsers/Oql/OqlParserBase.py']),
                  ])
+    py_files.extend([(xml('dom'), glob.glob('Dom/*.po'))])
 else:
     py_files.extend([('Ft.Lib', ['admin/DistExt.py', 'admin/install_data.py'])
                      ])
@@ -343,11 +343,6 @@
               'Ft.Lib',
               'Ft.Tools',
 
-              xml('dom'),
-              xml('dom.html'),
-              xml('dom.ext'),
-              xml('dom.ext.reader'),
-
               xml('xpath'),
 
               xml('xslt'),
@@ -574,7 +569,7 @@
                             files=glob.glob('Ods/demo/book_mark_manager/*.*')),
                  ]
 for df in ft_data_files:
-    df.base_dir = '$base/doc/$dist_name-$dist_version'
+    df.base_dir = '$base/share/doc/$dist_name'
 data_files.extend(ft_data_files)
 
 v = version.StrictVersion(__version__)
