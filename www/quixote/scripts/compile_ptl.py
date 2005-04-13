import sys
from quixote.ptl import ptl_compile

for srcfile in sys.argv[1:]:
  ptl_compile.compile(srcfile, srcfile + 'c')
