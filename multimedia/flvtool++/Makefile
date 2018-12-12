# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	flvtool++
PORTVERSION=	1.2.1
PORTREVISION=	11
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for hinting and manipulating the metadata of FLV files

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	Elbandi
GH_PROJECT=	flvtool-pp
GH_TAGNAME=	c0438e8

CFLAGS+=	-I${LOCALBASE}/include/boost
PLIST_FILES=	bin/flvtool++
USES=		scons

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/include/boost-1_33_1|${LOCALBASE}/include|' \
		${WRKSRC}/SConscript

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flvtool++ ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
