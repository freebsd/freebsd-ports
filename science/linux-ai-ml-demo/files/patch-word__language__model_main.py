--- word_language_model/main.py.orig	2025-03-17 17:25:58 UTC
+++ word_language_model/main.py
@@ -243,7 +243,7 @@ with open(args.save, 'rb') as f:
 
 # Load the best saved model.
 with open(args.save, 'rb') as f:
-    model = torch.load(f)
+    model = torch.load(f, weights_only=False)
     # after load the rnn params are not a continuous chunk of memory
     # this makes them a continuous chunk, and will speed up forward pass
     # Currently, only rnn model supports flatten_parameters function.
