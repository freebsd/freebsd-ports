# $FreeBSD$

PORTNAME=	httmock
PORTVERSION=	1.3.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		https://raw.githubusercontent.com/patrys/${PORTNAME}/${PORTVERSION}/:tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		tests.py:tests
DIST_SUBDIR=	py-${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Mocking library for requests

BROKEN=		unfetchable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.0.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

# Description: tests.py is missing from the pypi package
# Issue ID: https://github.com/patrys/httmock/issues/55
# TODO: Remove extra MASTER_SITES, DISTFILES/SUBDIR, EXTRACT_ONLY, post-extract
post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/tests.py ${WRKSRC}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
