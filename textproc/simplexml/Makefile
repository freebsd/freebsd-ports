# Ports collection makefile for:	simplexml
# Date created:				May 18 2010
# Whom:					Konstantin Lepa <konstantin.lepa@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	simplexml
PORTVERSION=	1.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://bitbucket.org/klepa/simplexml/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	konstantin.lepa@gmail.com
COMMENT=	C++ XML parser library

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GZIP=	yes
USE_CMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DDEBUG_MODE:BOOL=ON
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|; \
		/set.*CMAKE_BUILD_TYPE/d' ${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/cmake/FindIconv.cmake

.include <bsd.port.mk>
