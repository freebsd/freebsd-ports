# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	proj
PORTVERSION=	4.9.3
CATEGORIES=	math geography
MASTER_SITES=	http://download.osgeo.org/proj/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C language procedures related to cartographic processes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		cmake compiler
USE_LDCONFIG=	yes

FMAN1=	cs2cs.1 geod.1 proj.1
FMAN3=	geodesic.3 pj_init.3

pre-configure:
	${REINPLACE_CMD} -e 's|gcc|${COMPILER_TYPE}|'	\
		${WRKSRC}/cmake/Proj4SystemInfo.cmake

post-install:
.for m in 1 3
	(cd ${STAGEDIR}${MANPREFIX}/share/man/man${m} && ${GZIP_CMD} ${FMAN${m}})
.endfor

.include <bsd.port.mk>
