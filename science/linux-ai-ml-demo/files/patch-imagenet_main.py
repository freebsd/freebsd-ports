--- imagenet/main.py.orig	2025-02-09 16:56:58 UTC
+++ imagenet/main.py
@@ -298,7 +298,7 @@ def main_worker(gpu, ngpus_per_node, args):
                 'best_acc1': best_acc1,
                 'optimizer' : optimizer.state_dict(),
                 'scheduler' : scheduler.state_dict()
-            }, is_best)
+            }, is_best, os.path.join(os.path.expanduser("~/pytorch-examples-temp/imagenet"), 'checkpoint.pth.tar'))
 
 
 def train(train_loader, model, criterion, optimizer, epoch, device, args):
@@ -412,7 +412,7 @@ def save_checkpoint(state, is_best, filename='checkpoi
 def save_checkpoint(state, is_best, filename='checkpoint.pth.tar'):
     torch.save(state, filename)
     if is_best:
-        shutil.copyfile(filename, 'model_best.pth.tar')
+        shutil.copyfile(filename, os.path.join(os.path.dirname(filename), 'model_best.pth.tar'))
 
 class Summary(Enum):
     NONE = 0
