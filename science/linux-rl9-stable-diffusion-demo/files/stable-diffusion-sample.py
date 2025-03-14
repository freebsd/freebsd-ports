import sys
import torch
from diffusers import StableDiffusionPipeline

model_id = "CompVis/stable-diffusion-v1-4"
device = "cuda" if torch.cuda.is_available() else "cpu"
if device == "cpu":
    print(
        "CUDA is not available\n"
        "Please ensure the following:\n"
        "1. NVIDIA GPU is present in the system\n"
        "2. NVIDIA Driver kernel module is loaded\n"
        "3. dummy-uvm library is preloaded"
        )
    sys.exit(1)

pipe = StableDiffusionPipeline.from_pretrained(model_id, torch_dtype=torch.float16)
pipe = pipe.to(device)

prompt = "a photo of an astronaut riding a horse on mars"
image = pipe(prompt).images[0]

image.save("astronaut_rides_horse.png")
print(f"Image saved to astronaut_rides_horse.png")
