from kokoro import KPipeline
from IPython.display import display, Audio
import soundfile as sf
import torch

pipeline = KPipeline(lang_code='a')

text = '''
FreeBSD is a free and open-source Unix-like operating system descended from the Berkeley Software Distribution (BSD). The first version was released in 1993 developed from 386BSD, one of the first fully functional and free Unix clones on affordable home-class hardware, and has since continuously been the most commonly used BSD-derived operating system.
'''

generator = pipeline(text, voice='af_heart')
for i, (gs, ps, audio) in enumerate(generator):
    print(i, gs, ps)
    display(Audio(data=audio, rate=24000, autoplay=i==0))
    sf.write(f'{i}.wav', audio, 24000)
