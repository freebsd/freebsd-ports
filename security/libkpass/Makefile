# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkpass
PORTVERSION=	5
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Library for a reading/writing KeePass 1.x DB

LICENSE=	GPLv3

LIB_DEPENDS=	libnettle.so:security/nettle

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		alias gettext gmake libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-Dbswap_32=bswap32 -Dbswap_16=bswap16 \
		-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl

PLIST_FILES=	include/kpass.h \
		lib/libkpass.a \
		lib/libkpass.so \
		lib/libkpass.so.1 \
		lib/libkpass.so.1.0.0

.include <bsd.port.mk>
