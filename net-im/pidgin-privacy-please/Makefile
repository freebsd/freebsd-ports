# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pidgin-privacy-please
PORTVERSION=	0.7.1
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Privacy plugin for the pidgin instant messenger

LICENSE=	GPLv2

BROKEN=		Unfetchable (google code has gone away)

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpurple.so:net-im/libpurple
BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20 intltool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
