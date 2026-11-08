PORTNAME=	tatsu
DISTVERSION=	5.24.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generate Python parsers from grammars in a variation of EBNF
WWW=		https://tatsu.readthedocs.io/en/stable/ \
		https://github.com/neogeny/TatSu

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 concurrent autoplist pytest

SHEBANG_FILES=	tatsu/g2e/__init__.py

PYTEST_IGNORED_TESTS=	\
		test_dot \
		test_02_previous_output_generator test_03_repeat_02 test_04_repeat_03 \
		test_05_parse_with_model test_06_generate_code test_08_compile_with_generated \
		test_12_walker test_13_diagram \
		test_cling_boot test_cling_grammar test_cling_grammar_json test_cling_help \
		test_cli_help test_cli_model test_cli_python # disable failing tests, see https://github.com/neogeny/TatSu/issues/436

# The upstream 'cling' console script collides with lang/cling; rename it.
post-patch:
	@${REINPLACE_CMD} -e 's|^cling = "tatsu.cling:cling_main"|tatsu-cling = "tatsu.cling:cling_main"|' ${WRKSRC}/pyproject.toml

NO_ARCH=	yes

# tests as of 5.24.0: 584 passed, 6 skipped, 16 deselected, 14 warnings in 33.47s (some tests fail on he first run due to missing files, but they succeed when run again, see https://github.com/neogeny/TatSu/issues/435)

.include <bsd.port.mk>
