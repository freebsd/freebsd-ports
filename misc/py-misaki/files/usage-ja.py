"""
To run:
uv venv --seed -p 3.11
uv pip install ".[en]"
uv run examples/usage.py    
"""

from misaki import ja

g2p = en.G2P(trf=False, fallback=None) # no transformer, American English

text = '素敵な午後をお過ごしください。また後ほどお会いしましょう。'

phonemes, tokens = g2p(text)

print(phonemes) # misˈɑki ɪz ə ʤˈitəpˈi ˈɛnʤən dəzˈInd fɔɹ kˈOkəɹO mˈɑdᵊlz.
