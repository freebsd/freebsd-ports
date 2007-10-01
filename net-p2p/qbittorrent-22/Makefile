# New ports collection makefile for:	qbittorrent
# Date created:				2007-04-01
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	qbittorrent
DISTVERSION=	1.0.0rc3
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Bittorrent client written in C++ / Qt4 using libtorrent

LIB_DEPENDS=	ccext2-1.5.0:${PORTSDIR}/devel/commoncpp \
		torrent.1:${PORTSDIR}/net-p2p/rblibtorrent-devel

USE_PYTHON=	2.3+
USE_QT_VER=	4
QT_NONSTANDARD=	yes
INSTALLS_ICONS=	yes
HAS_CONFIGURE=	yes
CONFIGURE_TARGET=	#
CONFIGURE_ARGS=	--with-libtorrent-inc="${LOCALBASE}/include" \
		--with-libtorrent-lib="${LOCALBASE}/lib"
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}"
MAKE_ENV=	QMAKESPEC="${QMAKESPEC}"

OPTIONS=	IMAGEMAGICK "Enable libmagick++ support" off

MAN1=		qbittorrent.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	Magick.10:${PORTSDIR}/graphics/ImageMagick
.else
CONFIGURE_ARGS+=--disable-libmagick
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|bin/qmake|bin/${QMAKE:T}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$$$PREFIX/share/man|${MANPREFIX}/man|' \
		${WRKSRC}/src/src.pro

.include <bsd.port.post.mk>
