"""
To run:
uv venv --seed -p 3.11
uv pip install ".[en]"
uv run examples/usage.py    
"""

from misaki import ko

g2p = ko.G2p()

text = '즐거운 오후 보내시고 나중에 다시 뵙겠습니다.'

phonemes, tokens = g2p(text)

print(phonemes)
