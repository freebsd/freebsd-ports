--- content/renderer/input/input_event_prediction.cc.orig	2018-08-06 10:06:45.824140000 +0200
+++ content/renderer/input/input_event_prediction.cc	2018-08-06 10:09:29.835896000 +0200
@@ -119,7 +119,8 @@
     if (predictor != pointer_id_predictor_map_.end()) {
       predictor->second->Update(data);
     } else {
-      pointer_id_predictor_map_.insert({event.id, SetUpPredictor()});
+      auto pair = std::make_pair(event.id, SetUpPredictor());
+      pointer_id_predictor_map_.insert(std::move(pair));
       pointer_id_predictor_map_[event.id]->Update(data);
     }
   }
