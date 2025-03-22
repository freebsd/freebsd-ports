--- run_python_examples.sh.orig	2025-02-09 16:56:58 UTC
+++ run_python_examples.sh
@@ -13,6 +13,8 @@ source $BASE_DIR/utils.sh
 BASE_DIR="$(pwd)/$(dirname $0)"
 source $BASE_DIR/utils.sh
 
+TEMP_DIR="$HOME/pytorch-examples-temp"
+
 USE_CUDA=$(python -c "import torchvision, torch; print(torch.cuda.is_available())")
 case $USE_CUDA in
   "True")
@@ -32,31 +34,31 @@ function dcgan() {
 
 function dcgan() {
   start
-  python main.py --dataset fake $CUDA_FLAG --mps --dry-run || error "dcgan failed"
+  python main.py --dataset fake --outf "$TEMP_DIR/dcgan" $CUDA_FLAG --mps --dry-run || error "dcgan failed"
 }
 
 function fast_neural_style() {
   start
-  if [ ! -d "saved_models" ]; then
+  if [ ! -d $TEMP_DIR/fast_neural_style/saved_models ]; then
     echo "downloading saved models for fast neural style"
     python download_saved_models.py
   fi
-  test -d "saved_models" || { error "saved models not found"; return; }
+  test -d $TEMP_DIR/fast_neural_style/saved_models || { error "saved models not found"; return; }
 
   echo "running fast neural style model"
-  python neural_style/neural_style.py eval --content-image images/content-images/amber.jpg --model saved_models/candy.pth --output-image images/output-images/amber-candy.jpg --cuda $CUDA --mps || error "neural_style.py failed"
+  python neural_style/neural_style.py eval --content-image images/content-images/amber.jpg --model $TEMP_DIR/fast_neural_style/saved_models/candy.pth --output-image $TEMP_DIR/fast_neural_style/amber-candy.jpg --cuda $CUDA --mps || error "neural_style.py failed"
 }
 
 function imagenet() {
   start
-  if [[ ! -d "sample/val" || ! -d "sample/train" ]]; then
-    mkdir -p sample/val/n
-    mkdir -p sample/train/n
-    curl -O "https://upload.wikimedia.org/wikipedia/commons/5/5a/Socks-clinton.jpg" || { error "couldn't download sample image for imagenet"; return; }
-    mv Socks-clinton.jpg sample/train/n
-    cp sample/train/n/* sample/val/n/
+  if [[ ! -d "$TEMP_DIR/imagenet/sample/val" || ! -d "$TEMP_DIR/imagenet/sample/train" ]]; then
+    mkdir -p $TEMP_DIR/imagenet/sample/val/n
+    mkdir -p $TEMP_DIR/imagenet/sample/train/n
+    curl -o "$TEMP_DIR/imagenet/Socks-clinton.jpg" -O "https://upload.wikimedia.org/wikipedia/commons/5/5a/Socks-clinton.jpg"  || { error "couldn't download sample image for imagenet"; return; }
+    mv $TEMP_DIR/imagenet/Socks-clinton.jpg $TEMP_DIR/imagenet/sample/train/n
+    cp $TEMP_DIR/imagenet/sample/train/n/* $TEMP_DIR/imagenet/sample/val/n/
   fi
-  python main.py --epochs 1 sample/ || error "imagenet example failed"
+  python main.py --epochs 1 $TEMP_DIR/imagenet/sample/ || error "imagenet example failed"
 }
 
 function language_translation() {
@@ -144,7 +146,7 @@ function word_language_model() {
 
 function word_language_model() {
   start
-  python main.py --epochs 1 --dry-run $CUDA_FLAG --mps || error "word_language_model failed"
+  python main.py --epochs 1 --dry-run $CUDA_FLAG --mps --save $TEMP_DIR/word_language_model/wlm-model.pt || error "word_language_model failed"
 }
 
 function gcn() {
