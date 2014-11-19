# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/libsocialweb/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	libsocialweb
PORTVERSION=	0.25.21
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Personal social data server.

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala
LIB_DEPENDS=	librest-0.7.so:${PORTSDIR}/devel/librest \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gconf2 glib20 intlhack introspection:build \
		libxslt:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-vala-bindings
# review if we want all the services enabled, because of not completely
# safe public API security wise?
CONFIGURE_ARGS+=--enable-all-services 
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
