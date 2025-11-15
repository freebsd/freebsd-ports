--- ts/util/os/osMain.node.ts.orig	2025-05-23 14:04:11 UTC
+++ ts/util/os/osMain.node.ts
@@ -6,7 +6,7 @@ function getLinuxName(): string | undefined {
 import { getOSFunctions } from './shared';
 
 function getLinuxName(): string | undefined {
-  if (os.platform() !== 'linux') {
+  if (os.platform() !== 'freebsd') {
     return undefined;
   }
 
@@ -24,7 +24,7 @@ function isLinuxUsingKDE(): boolean {
 }
 
 function isLinuxUsingKDE(): boolean {
-  return os.platform() === 'linux' && process.env.XDG_CURRENT_DESKTOP === 'KDE';
+  return os.platform() === 'freebsd' && process.env.XDG_CURRENT_DESKTOP === 'KDE';
 }
 
 const OS = {
