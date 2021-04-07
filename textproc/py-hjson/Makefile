PORTNAME=	hjson
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.2
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	User interface for JSON written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
# Use GitHub instead of CHEESESHOP to get the test files.
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-py
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
