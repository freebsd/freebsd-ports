# Pre-generate a few files to avoid fs-violations in poudriere:
#
# ${PYTHON_SITELIBDIR}/spdx_tools/spdx/parser/tagvalue/parser.out
# ${PYTHON_SITELIBDIR}/spdx_tools/spdx/parser/tagvalue/parser.py
#

import spdx_tools.spdx.parser.tagvalue.tagvalue_parser as tvp

tvp.Parser()
