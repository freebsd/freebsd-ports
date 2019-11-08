# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	uget
PORTVERSION=	2.2.1
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/urlget/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	ndowens@yahoo.com
COMMENT=	Lightweight and full-featured graphical download manager

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	aria2c:www/aria2

USES=		compiler:c11 gettext-tools gmake gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 intltool cairo
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

# Avoid warning, with redefinition of typedef (C11 feature)
CFLAGS+=	-Wno-typedef-redefinition

CONFIGURE_ARGS=	--enable-appindicator=no \
		--disable-pwmd \
		--disable-rss-notify \
		--enable-unix-socket

OPTIONS_DEFINE=	GNUTLS GSTREAMER NLS NOTIFY OPENSSL
OPTIONS_DEFAULT=	NOTIFY OPENSSL
OPTIONS_SUB=	yes

GNUTLS_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GNUTLS_CONFIGURE_ON=	--with-gnutls=yes

GSTREAMER_USE=	gstreamer1=yes
GSTREAMER_CONFIGURE_ENABLE=	gstreamer

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	notify

OPENSSL_USES=	ssl
OPENSSL_CONFIGURE_ENV=	LIBCRYPTO_CFLAGS="-I${OPENSSLINC}" \
			LIBCRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto"
OPENSSL_CONFIGURE_OFF=	--with-openssl=no

.include <bsd.port.mk>
