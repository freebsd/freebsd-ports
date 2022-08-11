PORTNAME=	gssdp
PORTVERSION=	1.4.0.1
CATEGORIES=	net
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	14

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib>=2.54:devel/glib20 \
		gobject-introspection>=1.36:devel/gobject-introspection \
		libsoup>=2.26.1:devel/libsoup
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

MESON_ARGS=	-Dexamples=false -Dgtk_doc=false -Dintrospection=true
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	gssdp

PORTSCOUT=	limit:^1\.4\.

OPTIONS_DEFINE=	SNIFFER VAPI
OPTIONS_SUB=	yes
SNIFFER_DESC=	Build graphical SSDP sniffer

SNIFFER_BUILD_DEPENDS=	gtk4>=4:x11-toolkits/gtk40
SNIFFER_MESON_TRUE=	sniffer
SNIFFER_USE=		GNOME=gtk40
VAPI_BUILD_DEPENDS=	vala>=0.20:lang/vala
VAPI_MESON_TRUE=	vapi

.include <bsd.port.mk>
