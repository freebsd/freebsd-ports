https://github.com/apache/incubator-mxnet/issues/17076

--- src/operator/numpy/np_einsum_op-inl.h.orig	2019-12-15 04:21:16 UTC
+++ src/operator/numpy/np_einsum_op-inl.h
@@ -701,7 +701,7 @@ inline void NumpyEinsumProcess(const std::vector<TBlob
                               rstride_arr,
                               nop,
                               -1,
-                              reinterpret_cast<DType*>(NULL));
+                              (DType*)nullptr);
         })
       })
     })
@@ -947,7 +947,7 @@ inline void NumpyEinsumBackward(const OpStatePtr& stat
       if (handle_out) {
         temp_inputs.push_back(inputs[0]);
       } else {
-        temp_inputs.push_back(TBlob(reinterpret_cast<DType*>(NULL),
+        temp_inputs.push_back(TBlob((DType*)nullptr,
                                     paths[i].oshape,
                                     xpu::kDevMask));
       }
@@ -958,10 +958,10 @@ inline void NumpyEinsumBackward(const OpStatePtr& stat
           temp_outputs.push_back(outputs[idx - 1]);
           temp_req.push_back(req[idx - 1]);
         } else {
-          temp_inputs.push_back(TBlob(reinterpret_cast<DType*>(NULL),
+          temp_inputs.push_back(TBlob((DType*)nullptr,
                                       paths[-idx].oshape,
                                       xpu::kDevMask));
-          temp_outputs.push_back(TBlob(reinterpret_cast<DType*>(NULL),
+          temp_outputs.push_back(TBlob((DType*)nullptr,
                                       paths[-idx].oshape,
                                       xpu::kDevMask));
           temp_req.push_back(OpReqType::kWriteTo);
@@ -973,7 +973,7 @@ inline void NumpyEinsumBackward(const OpStatePtr& stat
           cur_tensordot_tempspace_size =
             TensordotBackwardWorkspaceSize<xpu>(paths[i].left_pos,
                                                 paths[i].right_pos,
-                                                TBlob(reinterpret_cast<DType*>(NULL),
+                                                TBlob((DType*)nullptr,
                                                       paths[i].tshape,
                                                       xpu::kDevMask),
                                                 temp_inputs[1],
