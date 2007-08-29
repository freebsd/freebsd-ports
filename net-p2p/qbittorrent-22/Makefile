# New ports collection makefile for:	qbittorrent
# Date created:				2007-04-01
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	qbittorrent
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Bittorrent client written in C++ / Qt4 using libtorrent

LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl \
		torrent.1:${PORTSDIR}/net-p2p/rblibtorrent

USE_PYTHON=	2.3+
USE_QT_VER=	4
QT_NONSTANDARD=	yes
INSTALLS_ICONS=	yes
HAS_CONFIGURE=	yes
CONFIGURE_TARGET=	#
CONFIGURE_ARGS=	--with-libtorrent-inc="${LOCALBASE}/include" \
		--with-libtorrent-lib="${LOCALBASE}/lib" \
		--with-libcurl-inc="${LOCALBASE}/include" \
		--with-libcurl-lib="${LOCALBASE}/lib"
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}"
MAKE_ENV=	QMAKESPEC="${QMAKESPEC}"

MAN1=		qbittorrent.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|bin/qmake|bin/${QMAKE:T}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$$$PREFIX/share/man|${MANPREFIX}/man|' \
		${WRKSRC}/src/src.pro

.include <bsd.port.mk>
