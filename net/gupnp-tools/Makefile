PORTNAME=	gupnp-tools
PORTVERSION=	0.12.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of utilities and demos to work with UPnP
WWW=		https://wiki.gnome.org/Projects/GUPnP \
		https://gitlab.gnome.org/GNOME/gupnp-tools

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib>=2.68:devel/glib20 \
		gssdp>=1.6.2:net/gssdp \
		gtk3>=3.10:x11-toolkits/gtk30 \
		gupnp>=1.6.0:net/gupnp \
		libsoup3>=3.0:devel/libsoup3
LIB_DEPENDS=	libgssdp-1.6.so:net/gssdp \
		libgupnp-1.6.so:net/gupnp \
		libsoup-3.0.so:devel/libsoup3

USES=		gettext-tools gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 gtk30 libxml2

CFLAGS+=	-Wno-error=deprecated-declarations
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	AV_TOOLS
OPTIONS_DEFAULT=AV_TOOLS

AV_TOOLS_MESON_TRUE=	av-tools
AV_TOOLS_BUILD_DEPENDS=	gupnp-av>=0.5.5:net/gupnp-av
AV_TOOLS_LIB_DEPENDS=	libgupnp-av-1.0.so:net/gupnp-av

.include <bsd.port.mk>
