--- x/imagegen/models/zimage/vae.go.orig	1979-11-30 08:00:00 UTC
+++ x/imagegen/models/zimage/vae.go
@@ -332,6 +332,16 @@ func (rb *ResnetBlock2D) Forward(x *mlx.Array) *mlx.Ar
 
 // Forward applies the ResNet block with staged evaluation
 func (rb *ResnetBlock2D) Forward(x *mlx.Array) *mlx.Array {
+	// Keep x alive across intermediate Eval calls (cleanup() would free it otherwise).
+	// The residual connection at the end needs the original x.
+	wasKept := x.Kept()
+	mlx.Keep(x)
+	defer func() {
+		if !wasKept {
+			x.Free()
+		}
+	}()
+
 	var h *mlx.Array
 
 	// Stage 1: norm1
@@ -461,6 +471,15 @@ func (ab *VAEAttentionBlock) Forward(x *mlx.Array) *ml
 // Input and output are in NHWC format [B, H, W, C]
 func (ab *VAEAttentionBlock) Forward(x *mlx.Array) *mlx.Array {
 	residual := x
+	// Keep residual alive across intermediate Eval calls.
+	// The residual addition at stage 3 needs the original input.
+	wasKept := residual.Kept()
+	mlx.Keep(residual)
+	defer func() {
+		if !wasKept {
+			residual.Free()
+		}
+	}()
 	shape := x.Shape()
 	B := shape[0]
 	H := shape[1]
