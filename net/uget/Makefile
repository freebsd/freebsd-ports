# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	uget
PORTVERSION=	2.0
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	urlget/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Download manager application

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	curl-config:${PORTSDIR}/ftp/curl
LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	aria2c:${PORTSDIR}/www/aria2

USES=	gmake pkgconfig gettext-tools compiler:c11
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 intltool intlhack
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

# Avoid warning, with redefinition of typedef (C11 feature)
CFLAGS+=	-Wno-typedef-redefinition

CONFIGURE_ARGS=--enable-appindicator=no \
	--disable-pwmd

OPTIONS_DEFINE=	GNUTLS GSTREAMER NLS
OPTIONS_DEFAULT=	GNUTLS GSTREAMER NLS
GSTREAMER_USE=	gstreamer1=yes
GSTREAMER_CONFIGURE_ENABLE=	gstreamer
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
	libgcrypt.so:${PORTSDIR}/security/libgcrypt
GNUTLS_CONFIGURE_WITH=	gnutls=yes
OPTIONS_SUB=	yes

.include <bsd.port.mk>
