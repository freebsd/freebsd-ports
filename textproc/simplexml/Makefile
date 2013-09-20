# Created by: Konstantin Lepa <konstantin.lepa@gmail.com>
# $FreeBSD$

PORTNAME=	simplexml
PORTVERSION=	1.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://bitbucket.org/klepa/simplexml/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	konstantin.lepa@gmail.com
COMMENT=	C++ XML parser library

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USES=		cmake iconv
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DDEBUG_MODE:BOOL=ON
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|; \
		/set.*CMAKE_BUILD_TYPE/d' ${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/cmake/FindIconv.cmake

.include <bsd.port.mk>
