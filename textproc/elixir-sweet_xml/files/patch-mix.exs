--- mix.exs.orig	2015-07-15 14:25:56 UTC
+++ mix.exs
@@ -26,8 +26,6 @@ defmodule SweetXml.Mixfile do
 
   defp deps do
     [
-      {:ex_doc, "~> 0.7", only: :dev},
-      {:markdown, github: "devinus/markdown"}
     ]
   end
 end
