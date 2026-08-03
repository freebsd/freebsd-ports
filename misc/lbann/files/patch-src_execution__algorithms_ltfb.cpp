-- fix failure on i386 - this is likely needed on all 32-bit architectures

--- src/execution_algorithms/ltfb.cpp.orig	2026-08-03 15:32:23 UTC
+++ src/execution_algorithms/ltfb.cpp
@@ -120,6 +120,6 @@ lbann::make<lbann::LTFB>(google::protobuf::Message con
     msg.name(),
     make_abstract<TrainingAlgorithm>(params.local_training_algorithm()),
     make_abstract<ltfb::MetaLearningStrategy>(params.meta_learning_strategy()),
-    ltfb::LTFBTerminationCriteria{stopping.max_tournaments()},
+    ltfb::LTFBTerminationCriteria{static_cast<size_t>(stopping.max_tournaments())},
     params.suppress_timer_output());
 }
