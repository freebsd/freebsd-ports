PORTNAME=	unyt
DISTVERSION=	2.8.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for handling numpy arrays with units
WWW=		https://github.com/yt-project/unyt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.2:math/py-sympy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test: # tests fail: https://github.com/yt-project/unyt/issues/192
	@cd ${WRKSRC} && pytest

.include <bsd.port.mk>
