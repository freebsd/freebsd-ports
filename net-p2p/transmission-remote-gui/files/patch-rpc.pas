--- rpc.pas.orig	2020-12-27 23:03:22.112873000 -0500
+++ rpc.pas	2020-12-27 23:05:37.172555000 -0500
@@ -805,6 +805,7 @@
   req, args: TJSONObject;
   _fields: TJSONArray;
   i: integer;
+  sl: TStringList;
 begin
   Result:=nil;
   req:=TJSONObject.Create;
@@ -813,13 +814,22 @@
     args:=TJSONObject.Create;
     if TorrentId <> 0 then
       args.Add('ids', TJSONArray.Create([TorrentId]));
-    _fields:=TJSONArray.Create(Fields);
-    for i:=Low(ExtraFields) to High(ExtraFields) do
-      _fields.Add(ExtraFields[i]);
+    _fields:=TJSONArray.Create;
+    for i:=Low(Fields) to High(Fields) do
+      if (Fields[i].VType=vtAnsiString) then
+         sl.Add(String(Fields[i].VAnsiString));
+    sl.AddStrings(ExtraFields);
+    sl.Sort;
+    for i:=sl.Count-2 downto 0 do
+      if (sl[i]=sl[i+1]) then
+        sl.Delete(i+1);
+    for i:=0 to sl.Count-1 do
+      _fields.Add(sl[i]);  
     args.Add('fields', _fields);
     req.Add('arguments', args);
     Result:=SendRequest(req);
   finally
+    sl.Free;
     req.Free;
   end;
 end;
