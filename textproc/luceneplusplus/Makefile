# $FreeBSD$

PORTNAME=	lucene++
PORTVERSION=	3.0.7
DISTVERSIONPREFIX=	rel_
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	arved@FreeBSD.org
COMMENT=	C++ port of the Lucene library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPL.license

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	luceneplusplus
GH_PROJECT=	LucenePlusPlus
USES=		cmake:outsource compiler
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} "/cotire/d" ${WRKSRC}/src/contrib/CMakeLists.txt \
		${WRKSRC}/src/core/CMakeLists.txt \
		${WRKSRC}/src/test/CMakeLists.txt

post-install:
	cd ${WRKSRC}/include &&${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/lucene++/

.include <bsd.port.post.mk>
