# New ports collection makefile for:	sharktorrent
# Date created:				2007-04-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sharktorrent
PORTVERSION=	0.1.8.4
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ Bittorrent client using wxWidgets, libtorrent and boost

LIB_DEPENDS=	boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		torrent-rasterbar.5:${PORTSDIR}/net-p2p/libtorrent-rasterbar-14

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build corelib gui network
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/sharktorrent

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|/opt|${LOCALBASE}|; s|-mt||' \
		${WRKSRC}/src/src.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} sharktorrent.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
