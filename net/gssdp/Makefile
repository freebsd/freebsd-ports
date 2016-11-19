# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gssdp
PORTVERSION=	1.0.1
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gobject-introspection>=0.6.7:devel/gobject-introspection
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

OPTIONS_DEFINE=	GTK3 VALA
OPTIONS_DEFAULT=GTK3
OPTIONS_SUB=	yes
VALA_DESC=	Vala binding

CONFIGURE_ARGS=	--enable-introspection=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig tar:xz

GTK3_CONFIGURE_WITH=	gtk
GTK3_USE=		GNOME=gtk30
VALA_BUILD_DEPENDS=	vala>=0.20:lang/vala
VALA_CONFIGURE_ENV=	ac_cv_path_VAPIGEN=${LOCALBASE}/bin/vapigen
VALA_CONFIGURE_ENV_OFF=	ac_cv_path_VAPIGEN=""

.include <bsd.port.mk>
