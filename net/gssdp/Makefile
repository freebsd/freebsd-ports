PORTNAME=	gssdp
PORTVERSION=	1.6.4
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices
WWW=		https://wiki.gnome.org/Projects/GUPnP

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib>=2.70:devel/glib20 \
		gobject-introspection>=1.36:devel/gobject-introspection \
		libsoup3>=2.99.0:devel/libsoup3
LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

MESON_ARGS=	--default-library=both -Dexamples=false -Dgtk_doc=false -Dintrospection=true -Dmanpages=false
USE_CSTD=	c11
USE_LDCONFIG=	yes

PLIST_SUB=	PATCH_VERSION=${PORTVERSION:E}

CONFLICTS_INSTALL=	gssdp14

OPTIONS_DEFINE=	SNIFFER VAPI
OPTIONS_SUB=	yes
SNIFFER_DESC=	Build graphical SSDP sniffer

SNIFFER_BUILD_DEPENDS=	gtk4>=4:x11-toolkits/gtk40
SNIFFER_MESON_TRUE=	sniffer
SNIFFER_USE=		GNOME=gtk40
VAPI_MESON_TRUE=	vapi
VAPI_USES=		vala:build

.include <bsd.port.mk>
