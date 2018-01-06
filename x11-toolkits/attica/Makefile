# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	attica
PORTVERSION=	0.4.2
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Open Collaboration Services API library

USE_QT4=	network qtestlib_build xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes
USES=		cmake:outsource tar:bzip2
CMAKE_ARGS=	-DATTICA_ENABLE_TESTS:BOOL=OFF \
		-DQT4_BUILD:BOOL=ON
USE_CXXSTD=	gnu++98

post-patch:
# LIB_DESTINATION is not caught by USES=pathfix.
	${REINPLACE_CMD} \
		-e 's,$${LIB_DESTINATION}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/lib/CMakeLists.txt
# By default attica will produce libattica.0.4.so but not libattica.0.so.
	${REINPLACE_CMD} \
		-e 's,.$${CMAKE_LIBATTICA_VERSION_MINOR},,' \
		${WRKSRC}/lib/CMakeLists.txt
# Install headers into a subdirectory of ${LOCALBASE}/include so that passing
# -I${LOCALBASE}/include does not cause it to be preferred over the KF5 version
# installed into ${LOCALBASE}/include/KF5.
	${REINPLACE_CMD} \
                -e "s,include/attica,include/attica/attica," \
		${WRKSRC}/lib/CMakeLists.txt
	${REINPLACE_CMD} \
		-e "s,/include,/include/attica," \
		${WRKSRC}/lib/cmake/libattica.pc.cmake

.include <bsd.port.mk>
