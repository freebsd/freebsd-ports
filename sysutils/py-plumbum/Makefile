# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plumbum
PORTVERSION=	1.6.5
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Shell combinators and more for python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils
GH_ACCOUNT=	tomerfiliba

do-test:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
