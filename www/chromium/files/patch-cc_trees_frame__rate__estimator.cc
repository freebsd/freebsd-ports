--- cc/trees/frame_rate_estimator.cc.orig	2021-04-14 18:40:48 UTC
+++ cc/trees/frame_rate_estimator.cc
@@ -48,7 +48,7 @@ void FrameRateEstimator::WillDraw(base::TimeTicks now)
   // frequency is lower than that, then using a lower frame rate is permitted.
   // The delta below is to account for minor offsets in frame times.
   constexpr auto kFudgeDelta = base::TimeDelta::FromMilliseconds(1);
-  constexpr auto kMinDelta =
+  auto kMinDelta =
       (viz::BeginFrameArgs::DefaultInterval() * 2) + kFudgeDelta;
   if (draw_delta < kMinDelta)
     num_of_consecutive_frames_with_min_delta_++;
