PORTNAME=	evalidate
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.4
CATEGORIES=	math python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Safe evaluation of untrusted user-supplied python expressions
WWW=		https://github.com/yaroslaff/evalidate

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.27.0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517 pytest
SHEBANG_FILES=	benchmark/benchmark.py \
		evalidate/__init__.py \
		evalidate/cli/genfakeproducts.py \
		evalidate/cli/jg.py \
		examples/basic.py

PYTEST_BROKEN_TESTS=	test_mul_overflow # tests/test_jailbreak.py::TestJailbreak::test_mul_overflow uses 12+GB of memory, see https://github.com/yaroslaff/evalidate/issues/8
TEST_ARGS=	--disable-plugin-autoload

USE_GITHUB=	yes
GH_ACCOUNT=	yaroslaff

NO_ARCH=	yes

# tests as of 2.1.4: 31 passed, 1 deselected in 0.05s

.include <bsd.port.mk>
