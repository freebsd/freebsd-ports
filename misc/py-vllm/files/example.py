from vllm import LLM, SamplingParams

if __name__ == '__main__':
    # 1. Load an open-source model
    # Use a modest max_model_len and gpu_memory_utilization so the example
    # fits on a typical CPU-only FreeBSD workstation.
    llm = LLM(
        model="TinyLlama/TinyLlama-1.1B-Chat-v1.0",
        max_model_len=512,
        gpu_memory_utilization=0.4,
    )

    # 2. Define how the model should generate text
    sampling_params = SamplingParams(temperature=0.7, max_tokens=50)

    # 3. Prompt the model
    prompts = ["The best part about learning AI is",
               "The toughest part of studying chemistry is"]
    outputs = llm.generate(prompts, sampling_params)

    # 4. Print the result
    print(f'numOutputs={len(outputs)}')
    num = 0
    for output in outputs:
        num += 1
        print(f'num={num}: output={output.outputs[0].text}')

