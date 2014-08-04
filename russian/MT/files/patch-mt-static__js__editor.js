--- mt-static/js/editor.js.orig	2013-12-02 02:40:32.000000000 +0900
+++ mt-static/js/editor.js	2014-04-16 15:20:42.000000000 +0900
@@ -1,4 +1,4 @@
-/* Movable Type (r) Open Source (C) 2001-2013 Six Apart, Ltd.
+/* Movable Type (r) Open Source (C) 2001-2014 Six Apart, Ltd.
  * This file is combined from multiple sources.  Consult the source files for their
  * respective licenses and copyrights.
  */;(function($){MT.EditorManager=function(){this.init.apply(this,arguments);};$.extend(MT.EditorManager,{editors:{},editorsForFormat:{},map:{},defaultWrapTag:'div',defaultWrapClass:'mt-editor-manager-wrap',register:function(id,editor){var thisConstructor=this;this.editors[id]=editor;$.each(editor.formatsForCurrentContext(),function(){if(!thisConstructor.editorsForFormat[this]){thisConstructor.editorsForFormat[this]=[];}
