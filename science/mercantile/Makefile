PORTNAME=	mercantile
DISTVERSION=	1.2.1
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Spherical mercator coordinate and tile utilities
WWW=		https://github.com/mapbox/mercantile

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.0:devel/py-click@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes
GH_ACCOUNT=	mapbox

NO_ARCH=	yes

.include <bsd.port.mk>
