--- config/rspack/stylesheets.mjs.orig	2026-11-21 07:17:57 UTC
+++ config/rspack/stylesheets.mjs
@@ -9,6 +9,7 @@ import { STYLESHEET_QUERY, STYLESHEET_QUERY_RE } from 
 import tailwindConfig from '../tailwind.config.js';
 import { IS_EE, IS_JH, ROOT_PATH } from '../webpack.constants.js';
 import { STYLESHEET_QUERY, STYLESHEET_QUERY_RE } from './loader_rules.js';
+import * as sass from 'sass';
 
 const ENTRY_PREFIX = 'styles/';
 
@@ -62,6 +63,7 @@ function buildStylesheetRules({ sourceMap }) {
         {
           loader: 'sass-loader',
           options: {
+            implementation: sass,
             api: 'modern-compiler',
             sourceMap,
             sassOptions: {
