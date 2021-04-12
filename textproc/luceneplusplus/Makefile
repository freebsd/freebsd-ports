PORTNAME=	lucene++
PORTVERSION=	3.0.8
PORTREVISION=	1
DISTVERSIONPREFIX=	rel_
CATEGORIES=	textproc

MAINTAINER=	arved@FreeBSD.org
COMMENT=	C++ port of the Lucene library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPL.license

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	luceneplusplus
GH_PROJECT=	LucenePlusPlus
USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes
CMAKE_OFF=	ENABLE_TEST ENABLE_DEMO

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} "/cotire/d" ${WRKSRC}/src/contrib/CMakeLists.txt \
		${WRKSRC}/src/core/CMakeLists.txt \
		${WRKSRC}/src/test/CMakeLists.txt
	${REINPLACE_CMD} 's,include/pkgconfig,libdata/pkgconfig,;s,include/cmake,share/lucene++/cmake,' \
		${WRKSRC}/src/config/core/CMakeLists.txt \
		${WRKSRC}/src/config/contrib/CMakeLists.txt

.include <bsd.port.post.mk>
