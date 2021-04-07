PORTNAME=	triangle
PORTVERSION=	20200424
CATEGORIES=	math
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Python interface to triangle

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang python:3.6+

USE_PYTHON=	distutils autoplist

BUILD_DEPENDS=	triangle>0:math/triangle

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/triangle/core*.so

.include <bsd.port.mk>
