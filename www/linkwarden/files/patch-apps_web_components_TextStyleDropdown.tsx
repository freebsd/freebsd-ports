--- apps/web/components/TextStyleDropdown.tsx.orig	2026-09-23 09:02:23 UTC
+++ apps/web/components/TextStyleDropdown.tsx
@@ -13,12 +13,17 @@
 import { Button } from "@/components/ui/button";
 import { FitWidth, FormatLineSpacing, FormatSize } from "@/components/ui/icons";
 import { useUpdateUserPreference, useUser } from "@linkwarden/router/user";
-import { Caveat } from "next/font/google";
-import { Bentham } from "next/font/google";
+import localFont from "next/font/local";
 import { useTranslation } from "next-i18next";
 
-const caveat = Caveat({ subsets: ["latin"] });
-const bentham = Bentham({ subsets: ["latin"], weight: "400" });
+const caveat = localFont({
+  src: "../fonts/Caveat-Variable.ttf",
+  weight: "400 700",
+});
+const bentham = localFont({
+  src: "../fonts/Bentham-Regular.ttf",
+  weight: "400",
+});
 
 const fontSizes = [
   "12px",
