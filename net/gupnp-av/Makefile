PORTNAME=	gupnp-av
PORTVERSION=	0.14.5
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helpers for audio/video applications using GUPnP
WWW=		https://gnome.pages.gitlab.gnome.org/gupnp-av/docs/ \
		https://gitlab.gnome.org/GNOME/gupnp-av \
		https://github.com/GNOME/gupnp-av

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib>=2.58:devel/glib20 \
		gobject-introspection>=1.36:devel/gobject-introspection

USES=		compiler:c11 gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2

MESON_ARGS=	--default-library=both \
		-Dgtk_doc=false \
		-Dintrospection=true
USE_CSTD=	c11
USE_LDCONFIG=	yes

PLIST_SUB=	PATCH_VERSION=${PORTVERSION:E}

OPTIONS_DEFINE=	VAPI
OPTIONS_SUB=	yes

VAPI_USES=		vala:build
VAPI_MESON_TRUE=	vapi

.include <bsd.port.mk>
