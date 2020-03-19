--- library/Icinga/Web/View.php.orig	2019-10-18 05:39:24 UTC
+++ library/Icinga/Web/View.php
@@ -60,13 +60,6 @@ class View extends Zend_View_Abstract
     const CHARSET = 'UTF-8';
 
     /**
-     * Flag to register stream wrapper
-     *
-     * @var bool
-     */
-    private $useViewStream = false;
-
-    /**
      * Registered helper functions
      */
     private $helperFunctions = array();
@@ -86,13 +79,6 @@ class View extends Zend_View_Abstract
      */
     public function __construct($config = array())
     {
-        $this->useViewStream = (bool) ini_get('short_open_tag') ? false : true;
-        if ($this->useViewStream) {
-            if (!in_array('zend.view', stream_get_wrappers())) {
-                stream_wrapper_register('zend.view', '\Icinga\Web\ViewStream');
-            }
-        }
-
         $config['helperPath']['Icinga\\Web\\View\\Helper\\'] = Icinga::app()->getLibraryDir('Icinga/Web/View/Helper');
 
         parent::__construct($config);
@@ -258,11 +244,8 @@ class View extends Zend_View_Abstract
             // Exporting global variables to view scripts:
             $$k = $v;
         }
-        if ($this->useViewStream) {
-            include 'zend.view://' . func_get_arg(0);
-        } else {
-            include func_get_arg(0);
-        }
+
+           include func_get_arg(0);
     }
 
     /**
