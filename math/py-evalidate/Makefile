PORTNAME=	evalidate
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	math python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Safe evaluation of untrusted user-supplied python expressions
WWW=		https://github.com/yaroslaff/evalidate

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist pytest # the test tests/test_jailbreak.py::TestJailbreak::test_mul_overflow runs in  a very high memory - 12+GB, see https://github.com/yaroslaff/evalidate/issues/8

USE_GITHUB=	yes
GH_ACCOUNT=	yaroslaff

NO_ARCH=	yes

.include <bsd.port.mk>
