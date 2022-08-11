PORTNAME=	twitter
PORTVERSION=	1.19.3
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-tools

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	API and command-line toolset for Twitter (twitter.com)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	sixohsix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# A number of test failures are (still) present in test_util
# https://github.com/sixohsix/twitter/issues/166

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
