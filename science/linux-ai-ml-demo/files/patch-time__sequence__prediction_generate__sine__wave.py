--- time_sequence_prediction/generate_sine_wave.py.orig	2025-02-09 16:56:58 UTC
+++ time_sequence_prediction/generate_sine_wave.py
@@ -1,5 +1,6 @@ import torch
 import numpy as np
 import torch
+import os
 
 np.random.seed(2)
 
@@ -10,4 +11,4 @@ data = np.sin(x / 1.0 / T).astype('float64')
 x = np.empty((N, L), 'int64')
 x[:] = np.array(range(L)) + np.random.randint(-4 * T, 4 * T, N).reshape(N, 1)
 data = np.sin(x / 1.0 / T).astype('float64')
-torch.save(data, open('traindata.pt', 'wb'))
+torch.save(data, open(os.path.join(os.path.expanduser("~/pytorch-examples-temp/time_sequence_prediction"), 'traindata.pt'), 'wb'))
