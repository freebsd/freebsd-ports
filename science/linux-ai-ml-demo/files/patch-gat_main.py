--- gat/main.py.orig	2025-02-09 16:56:58 UTC
+++ gat/main.py
@@ -332,7 +332,8 @@ if __name__ == '__main__':
 
     # Load the dataset
     cora_url = 'https://linqs-data.soe.ucsc.edu/public/lbc/cora.tgz'
-    path = './cora'
+    temp_dir = os.path.expanduser("~/pytorch-examples-temp/gcn-gat")
+    path = os.path.join(temp_dir, './cora')
 
     if os.path.isfile(os.path.join(path, 'cora.content')) and os.path.isfile(os.path.join(path, 'cora.cites')):
         print('Dataset already downloaded...')
@@ -340,11 +341,11 @@ if __name__ == '__main__':
         print('Downloading dataset...')
         with requests.get(cora_url, stream=True) as tgz_file:
             with tarfile.open(fileobj=tgz_file.raw, mode='r:gz') as tgz_object:
-                tgz_object.extractall()
+                tgz_object.extractall(path=temp_dir)
 
     print('Loading dataset...')
     # Load the dataset
-    features, labels, adj_mat = load_cora(device=device)
+    features, labels, adj_mat = load_cora(path=path, device=device)
     # Split the dataset into training, validation, and test sets
     idx = torch.randperm(len(labels)).to(device)
     idx_test, idx_val, idx_train = idx[:1200], idx[1200:1600], idx[1600:]
@@ -372,4 +373,4 @@ if __name__ == '__main__':
         if args.dry_run:
             break
     loss_test, acc_test = test(gat_net, criterion, (features, adj_mat), labels, idx_test)
-    print(f'Test set results: loss {loss_test:.4f} accuracy {acc_test:.4f}')
\ No newline at end of file
+    print(f'Test set results: loss {loss_test:.4f} accuracy {acc_test:.4f}')
