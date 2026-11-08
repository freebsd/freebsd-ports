--- apps/web/components/Preservation/ReadableView.tsx.orig	2026-09-23 09:02:23 UTC
+++ apps/web/components/Preservation/ReadableView.tsx
@@ -25,13 +25,18 @@
 } from "@linkwarden/router/highlights";
 import { Highlight } from "@linkwarden/prisma/client";
 import { useUser } from "@linkwarden/router/user";
-import { Caveat } from "next/font/google";
-import { Bentham } from "next/font/google";
+import localFont from "next/font/local";
 import { Separator } from "../ui/separator";
 import { Button } from "../ui/button";
 
-const caveat = Caveat({ subsets: ["latin"] });
-const bentham = Bentham({ subsets: ["latin"], weight: "400" });
+const caveat = localFont({
+  src: "../../fonts/Caveat-Variable.ttf",
+  weight: "400 700",
+});
+const bentham = localFont({
+  src: "../../fonts/Bentham-Regular.ttf",
+  weight: "400",
+});
 
 type Props = {
   link: LinkIncludingShortenedCollectionAndTags;
