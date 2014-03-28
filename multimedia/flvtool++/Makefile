# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	flvtool++
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://mirror.facebook.net/facebook/flvtool++/

MAINTAINER=	gslin@gslin.org
COMMENT=	Tool for hinting and manipulating the metadata of FLV files

LIB_DEPENDS=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs

CFLAGS+=	-I${LOCALBASE}/include/boost
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/flvtool++
USES=		scons

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/include/boost-1_33_1|${LOCALBASE}/include|' \
		${WRKSRC}/SConscript

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flvtool++ ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
