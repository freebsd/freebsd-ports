#!%%PYTHON%%

import sys
import os
import shutil
from datetime import datetime
from kokoro import KPipeline
import soundfile as sf

def main():
    if len(sys.argv) != 3:
        print("Usage: kokoro-text-to-wav <text> <wav-output-file>", file=sys.stderr)
        sys.exit(1)
    
    text = sys.argv[1]
    output_file = sys.argv[2]
    
    timestamp = datetime.now().strftime("%Y%m%d%H%M%S%f")
    temp_dir = f"/tmp/kokoro-{timestamp}"
    
    try:
        os.makedirs(temp_dir, exist_ok=True)
        
        pipeline = KPipeline(lang_code='a')
        generator = pipeline(text, voice='af_heart')
        
        audio_data = None
        for _, _, audio in generator:
            audio_data = audio
        
        if audio_data is not None:
            sf.write(output_file, audio_data, 24000)
        else:
            print("Error: No audio generated", file=sys.stderr)
            sys.exit(1)
    
    finally:
        if os.path.exists(temp_dir):
            shutil.rmtree(temp_dir)

if __name__ == '__main__':
    main()
