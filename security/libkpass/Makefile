# New ports collection makefile for:	libkpass
# Date created:		2011-09-12
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	libkpass
PORTVERSION=	3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Library for a reading/writing KeePass 1.x DB

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-Dbswap_32=bswap32 -Dbswap_16=bswap16

PLIST_FILES=	include/kpass.h \
		lib/libkpass.so \
		lib/libkpass.so.0 \
		lib/libkpass.la \
		lib/libkpass.a

.include <bsd.port.mk>
