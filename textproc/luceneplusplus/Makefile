PORTNAME=	lucene++
PORTVERSION=	3.0.9
PORTREVISION=	3
DISTVERSIONPREFIX=	rel_
CATEGORIES=	textproc

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	C++ port of the Lucene library
WWW=		https://github.com/luceneplusplus/LucenePlusPlus

PATCH_SITES+=	https://github.com/luceneplusplus/LucenePlusPlus/commit/
PATCHFILES+=	c18ead2b0c4aa62af01450cb12353a0baa51411f.patch:-p1
PATCHFILES+=	e6a376836e5c891577eae6369263152106b9bc02.patch:-p1

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPL.license

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	luceneplusplus
GH_PROJECT=	LucenePlusPlus
USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes
CMAKE_OFF=	ENABLE_TEST ENABLE_DEMO

PLIST_SUB+=	LIBVERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} "/cotire/d" ${WRKSRC}/src/contrib/CMakeLists.txt \
		${WRKSRC}/src/core/CMakeLists.txt \
		${WRKSRC}/src/test/CMakeLists.txt
	${REINPLACE_CMD} 's,LIB_DESTINATION}/pkgconfig,CMAKE_INSTALL_LIBDIR}/pkgconfig,' \
		${WRKSRC}/src/config/core/CMakeLists.txt
	${FIND} ${WRKSRC} -name CMakeLists.txt | ${XARGS} \
		${REINPLACE_CMD} -e '/Boost::system/d'

.include <bsd.port.post.mk>
