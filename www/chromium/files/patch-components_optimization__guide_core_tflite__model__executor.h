--- components/optimization_guide/core/tflite_model_executor.h.orig	2024-01-30 07:53:34 UTC
+++ components/optimization_guide/core/tflite_model_executor.h
@@ -241,7 +241,11 @@ class TFLiteModelExecutor : public ModelExecutor<Outpu
   void SendForBatchExecution(
       BatchExecutionCallback callback_on_complete,
       base::TimeTicks start_time,
+#if defined(__clang__) && (__clang_major__ >= 15)
       ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs)
+#else
+      typename ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs)
+#endif
       override {
     DCHECK(execution_task_runner_->RunsTasksInCurrentSequence());
     DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -263,7 +267,11 @@ class TFLiteModelExecutor : public ModelExecutor<Outpu
   // Starts the synchronous execution of the model. Returns model outputs.
   // Model needs to be loaded. Synchronous calls do not load or unload model.
   std::vector<absl::optional<OutputType>> SendForBatchExecutionSync(
+#if defined(__clang__) && (__clang_major__ >= 15)
       ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs)
+#else
+      typename ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs)
+#endif
       override {
     DCHECK(execution_task_runner_->RunsTasksInCurrentSequence());
     DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -421,7 +429,11 @@ class TFLiteModelExecutor : public ModelExecutor<Outpu
   // executes it on the model execution thread.
   void LoadModelFileAndBatchExecute(
       BatchExecutionCallback callback_on_complete,
+#if defined(__clang__) && (__clang_major__ >= 15)
       ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs) {
+#else
+      typename ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs) {
+#endif
     DCHECK(execution_task_runner_->RunsTasksInCurrentSequence());
     DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
 
@@ -438,7 +450,11 @@ class TFLiteModelExecutor : public ModelExecutor<Outpu
 
   // Batch executes the loaded model for inputs.
   void BatchExecuteLoadedModel(
+#if defined(__clang__) && (__clang_major__ >= 15)
       ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs,
+#else
+      typename ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs,
+#endif
       std::vector<absl::optional<OutputType>>* outputs) {
     DCHECK(execution_task_runner_->RunsTasksInCurrentSequence());
     DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -498,7 +514,11 @@ class TFLiteModelExecutor : public ModelExecutor<Outpu
   // Unloads the model if needed.
   void BatchExecuteLoadedModelAndRunCallback(
       BatchExecutionCallback callback_on_complete,
+#if defined(__clang__) && (__clang_major__ >= 15)
       ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs,
+#else
+      typename ModelExecutor<OutputType, InputType>::ConstRefInputVector inputs,
+#endif
       ExecutionStatus execution_status) {
     DCHECK(execution_task_runner_->RunsTasksInCurrentSequence());
     DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
