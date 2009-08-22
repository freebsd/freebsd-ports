# New ports collection makefile for:	sharktorrent
# Date created:				2007-04-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sharktorrent
PORTVERSION=	0.1.1
PORTREVISION=	4
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	C++ Bittorrent client using wxWidgets, libtorrent and boost

LIB_DEPENDS=	boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		torrent.1:${PORTSDIR}/net-p2p/rblibtorrent

USE_WX=		2.6
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDLFAGS="-L${LOCALBASE}/lib"
CPPFLAGS=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libtorrent

PLIST_FILES=	bin/sharktorrent

.include <bsd.port.mk>
