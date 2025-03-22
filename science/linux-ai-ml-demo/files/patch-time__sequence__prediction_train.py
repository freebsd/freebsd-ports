--- time_sequence_prediction/train.py.orig	2025-02-09 16:56:58 UTC
+++ time_sequence_prediction/train.py
@@ -44,7 +44,7 @@ if __name__ == '__main__':
     np.random.seed(0)
     torch.manual_seed(0)
     # load data and make training set
-    data = torch.load('traindata.pt')
+    data = torch.load('traindata.pt', weights_only=False)
     input = torch.from_numpy(data[3:, :-1])
     target = torch.from_numpy(data[3:, 1:])
     test_input = torch.from_numpy(data[:3, :-1])
