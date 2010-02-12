# New ports collection makefile for:	sharktorrent
# Date created:				2007-04-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sharktorrent
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	C++ Bittorrent client using wxWidgets, libtorrent and boost

LIB_DEPENDS=	boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		torrent.1:${PORTSDIR}/net-p2p/rblibtorrent

DEPRECATED=	Version is out of date, relies on too-old version of libtorrent
EXPIRATION_DATE=	2010-03-15
USE_WX=		2.6
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDLFAGS="-L${LOCALBASE}/lib"
CPPFLAGS=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libtorrent

PLIST_FILES=	bin/sharktorrent

.include <bsd.port.mk>
