/*
 * Standalone C example exercising the core ONNX Runtime C API.
 * It loads a tiny Add model from the path given on the command line,
 * creates input tensors, runs inference, and verifies the result.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <onnxruntime_c_api.h>

#define CHECK_STATUS(expr)                                        \
  do {                                                            \
    OrtStatus* status__ = (expr);                                 \
    if (status__ != NULL) {                                       \
      const char* msg = g_ort->GetErrorMessage(status__);          \
      fprintf(stderr, "Error at %s:%d: %s\n", __FILE__, __LINE__, msg ? msg : "unknown"); \
      g_ort->ReleaseStatus(status__);                             \
      return 1;                                                   \
    }                                                             \
  } while (0)

static const OrtApi* g_ort = NULL;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <model.onnx>\n", argv[0]);
    return 1;
  }
  const char* model_path = argv[1];

  const OrtApiBase* api_base = OrtGetApiBase();
  if (api_base == NULL) {
    fprintf(stderr, "OrtGetApiBase() returned NULL\n");
    return 1;
  }
  g_ort = api_base->GetApi(ORT_API_VERSION);
  if (g_ort == NULL) {
    fprintf(stderr, "GetApi(%d) returned NULL\n", ORT_API_VERSION);
    return 1;
  }

  OrtEnv* env = NULL;
  CHECK_STATUS(g_ort->CreateEnv(ORT_LOGGING_LEVEL_WARNING, "example", &env));

  OrtSessionOptions* session_options = NULL;
  CHECK_STATUS(g_ort->CreateSessionOptions(&session_options));

  OrtSession* session = NULL;
  CHECK_STATUS(g_ort->CreateSession(env, model_path, session_options, &session));

  OrtMemoryInfo* memory_info = NULL;
  CHECK_STATUS(g_ort->CreateCpuMemoryInfo(OrtArenaAllocator, OrtMemTypeDefault, &memory_info));

  /* Two 2x2 matrices to add: expected result is [[3, 5], [7, 9]] */
  float a_data[4] = {1.0f, 2.0f, 3.0f, 4.0f};
  float b_data[4] = {2.0f, 3.0f, 4.0f, 5.0f};
  int64_t shape[2] = {2, 2};

  OrtValue* input_a = NULL;
  OrtValue* input_b = NULL;
  CHECK_STATUS(g_ort->CreateTensorWithDataAsOrtValue(memory_info, a_data, sizeof(a_data), shape, 2, ONNX_TENSOR_ELEMENT_DATA_TYPE_FLOAT, &input_a));
  CHECK_STATUS(g_ort->CreateTensorWithDataAsOrtValue(memory_info, b_data, sizeof(b_data), shape, 2, ONNX_TENSOR_ELEMENT_DATA_TYPE_FLOAT, &input_b));

  const char* input_names[2] = {"a", "b"};
  const OrtValue* inputs[2] = {input_a, input_b};
  const char* output_names[1] = {"c"};
  OrtValue* outputs[1] = {NULL};

  CHECK_STATUS(g_ort->Run(session, NULL, input_names, inputs, 2, output_names, 1, outputs));

  float* output_data = NULL;
  CHECK_STATUS(g_ort->GetTensorMutableData(outputs[0], (void**)&output_data));

  int ok = 1;
  float expected[4] = {3.0f, 5.0f, 7.0f, 9.0f};
  for (int i = 0; i < 4; ++i) {
    if (output_data[i] != expected[i]) {
      fprintf(stderr, "Mismatch at %d: got %f, expected %f\n", i, output_data[i], expected[i]);
      ok = 0;
    }
  }

  g_ort->ReleaseValue(outputs[0]);
  g_ort->ReleaseValue(input_a);
  g_ort->ReleaseValue(input_b);
  g_ort->ReleaseMemoryInfo(memory_info);
  g_ort->ReleaseSession(session);
  g_ort->ReleaseSessionOptions(session_options);
  g_ort->ReleaseEnv(env);

  if (ok) {
    printf("example.c: ONNX Runtime quick test succeeded\n");
    return 0;
  }
  printf("example.c: ONNX Runtime quick test failed\n");
  return 1;
}
