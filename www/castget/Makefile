# New ports collection makefile for:	castget
# Date created:		16 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	castget
PORTVERSION=	0.9.6
CATEGORIES=	www
MASTER_SITES=	SAVANNAH CSME

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Command-line podcast downloader

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		curl.4:${PORTSDIR}/ftp/curl

USE_LDCONFIG=	yes
USE_GNOME=	glib20 libxml2
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man --disable-static
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/castget include/libcastget.h lib/libcastget.la lib/libcastget.so lib/libcastget.so.0
MAN1=	castget.1
MAN5=	castgetrc.5

.include <bsd.port.mk>
