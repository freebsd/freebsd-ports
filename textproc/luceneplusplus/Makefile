# $FreeBSD$

PORTNAME=	lucene++
PORTVERSION=	3.0.7
CATEGORIES=	textproc

MAINTAINER=	arved@FreeBSD.org
COMMENT=	C++ port of the Lucene library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPL.license

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	luceneplusplus
GH_PROJECT=	LucenePlusPlus
GH_TAGNAME=	rel_3.0.7
GH_COMMIT=	4d28f9f
USES=		cmake:outsource
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-install:
	cd ${WRKSRC}/include &&${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/lucene++/

.include <bsd.port.post.mk>
