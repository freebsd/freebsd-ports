--- gcn/main.py.orig	2025-02-09 16:56:58 UTC
+++ gcn/main.py
@@ -241,12 +241,13 @@ if __name__ == '__main__':
 
     cora_url = 'https://linqs-data.soe.ucsc.edu/public/lbc/cora.tgz'
     print('Downloading dataset...')
+    temp_dir = os.path.expanduser("~/pytorch-examples-temp/gcn-gat")
     with requests.get(cora_url, stream=True) as tgz_file:
         with tarfile.open(fileobj=tgz_file.raw, mode='r:gz') as tgz_object:
-            tgz_object.extractall()
+            tgz_object.extractall(path=temp_dir)
 
     print('Loading dataset...')
-    features, labels, adj_mat = load_cora(device=device)
+    features, labels, adj_mat = load_cora(path=os.path.join(temp_dir, 'cora'), device=device)
     idx = torch.randperm(len(labels)).to(device)
     idx_test, idx_val, idx_train = idx[:1000], idx[1000:1500], idx[1500:]
 
@@ -260,4 +261,4 @@ if __name__ == '__main__':
             break
 
     loss_test, acc_test = test(gcn, criterion, (features, adj_mat), labels, idx_test)
-    print(f'Test set results: loss {loss_test:.4f} accuracy {acc_test:.4f}')
\ No newline at end of file
+    print(f'Test set results: loss {loss_test:.4f} accuracy {acc_test:.4f}')
