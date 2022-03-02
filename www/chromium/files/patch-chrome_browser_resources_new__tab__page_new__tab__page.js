--- chrome/browser/resources/new_tab_page/new_tab_page.js.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/resources/new_tab_page/new_tab_page.js
@@ -21,10 +21,6 @@ export {chromeCartDescriptor as chromeCartV2Descriptor
 export {DriveProxy} from './modules/drive/drive_module_proxy.js';
 export {driveDescriptor} from './modules/drive/module.js';
 export {driveDescriptor as driveV2Descriptor} from './modules/drive_v2/module.js';
-// <if expr="not is_official_build">
-export {FooProxy} from './modules/dummy_v2/foo_proxy.js';
-export {dummyV2Descriptor} from './modules/dummy_v2/module.js';
-// </if>
 export {InfoDialogElement} from './modules/info_dialog.js';
 export {InitializeModuleCallback, Module, ModuleDescriptor, ModuleDescriptorV2, ModuleHeight} from './modules/module_descriptor.js';
 export {ModuleHeaderElement} from './modules/module_header.js';
