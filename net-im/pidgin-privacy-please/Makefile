# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pidgin-privacy-please
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	net-im

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Privacy plugin for the pidgin instant messenger

BROKEN=		unfetchable

DEPRECATED=	Abandonware
EXPIRATION_DATE=	2019-12-09

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpurple.so:net-im/libpurple
BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

GNU_CONFIGURE=	yes
USES=		autoreconf gettext gmake gnome libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20 intltool
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cockroach
GH_TAGNAME=	21e7046

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
