PORTNAME=	evalidate
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.3
CATEGORIES=	math python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Safe evaluation of untrusted user-supplied python expressions
WWW=		https://github.com/yaroslaff/evalidate

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist pytest

PYTEST_BROKEN_TESTS=	test_mul_overflow # tests/test_jailbreak.py::TestJailbreak::test_mul_overflow uses 12+GB of memory, see https://github.com/yaroslaff/evalidate/issues/8

USE_GITHUB=	yes
GH_ACCOUNT=	yaroslaff

NO_ARCH=	yes

# tests as of 2.1.3: 33 passed, 2 warnings in 10.93s

.include <bsd.port.mk>
