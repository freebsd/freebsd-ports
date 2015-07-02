--- Headers/AppKit/NSTableView.h
+++ Headers/AppKit/NSTableView.h
@@ -91,7 +91,7 @@
   BOOL               _drawsGrid;
   NSColor           *_gridColor;
   NSColor           *_backgroundColor;
-  float              _rowHeight;
+  CGFloat            _rowHeight;
   NSSize             _intercellSpacing;
   id                 _delegate;
   NSTableHeaderView *_headerView;
