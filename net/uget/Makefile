# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	uget
DISTVERSION=	2.0.7-2
CATEGORIES=	net
MASTER_SITES=	SF/urlget/${PORTNAME}%20%28stable%29/${DISTVERSION:S/-2//}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Download manager application

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	curl-config:ftp/curl
LIB_DEPENDS=	libnotify.so:devel/libnotify \
	libgcrypt.so:security/libgcrypt \
	libgnutls.so:security/gnutls
RUN_DEPENDS=	aria2c:www/aria2

USES=	compiler:c11 gettext-tools gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 intltool intlhack
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION:S/-2$//}

# Avoid warning, with redefinition of typedef (C11 feature)
CFLAGS+=	-Wno-typedef-redefinition

CONFIGURE_ARGS=--enable-appindicator=no \
	--disable-pwmd \
	--with-gnutls=yes

OPTIONS_DEFINE=	GSTREAMER NLS
OPTIONS_DEFAULT=	GSTREAMER NLS
GSTREAMER_USE=	gstreamer1=yes
GSTREAMER_CONFIGURE_ENABLE=	gstreamer
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

.include <bsd.port.mk>
