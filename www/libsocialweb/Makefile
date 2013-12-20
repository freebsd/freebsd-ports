# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/libsocialweb/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libsocialweb
PORTVERSION=	0.25.20
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Personal social data server.

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	librest-0.7.so:${PORTSDIR}/devel/librest \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

USE_GNOME=	gconf2 glib20 gnomehier intlhack introspection:build \
		libxslt:build
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gettext gmake pathfix pkgconfig
CONFIGURE_ARGS=	--enable-vala-bindings
# review if we want all the services enabled, because of not completely
# safe public API security wise?
CONFIGURE_ARGS+=--enable-all-services 

.include <bsd.port.mk>
