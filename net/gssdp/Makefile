# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gssdp
PORTVERSION=	0.14.3
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices

LICENSE=	LGPL20

BUILD_DEPENDS=	gobject-introspection>=0.6.7:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	soup-2.4:${PORTSDIR}/devel/libsoup

OPTIONS_DEFINE=	GTK3
OPTIONS_DEFAULT=GTK3

CONFIGURE_ARGS=	--enable-introspection=yes
CONFIGURE_ENV=	VAPIGEN=""
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		gmake pathfix pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK3}
CONFIGURE_ARGS+=--with-gtk
USE_GNOME+=	gtk30
PLIST_SUB=	GTK3=""
.else
CONFIGURE_ARGS+=--without-gtk
PLIST_SUB=	GTK3="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|__OpenBSD__|__FreeBSD__|' ${WRKSRC}/libgssdp/gssdp-socket-functions.c

.include <bsd.port.mk>
