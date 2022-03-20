# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	gupnp-tools
PORTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of utilities and demos to work with UPnP

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib>=2.24:devel/glib20 \
		gssdp>=1.2.0:net/gssdp \
		gtk3>=3.10:x11-toolkits/gtk30 \
		gupnp>=1.2.0:net/gupnp \
		libsoup>=2.42:devel/libsoup
LIB_DEPENDS=	libgssdp-1.2.so:net/gssdp \
		libgupnp-1.2.so:net/gupnp \
		libsoup-2.4.so:devel/libsoup

USES=		gettext gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 gtk30 libxml2

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	AV_TOOLS
OPTIONS_DEFAULT=AV_TOOLS

AV_TOOLS_MESON_TRUE=	av-tools
AV_TOOLS_BUILD_DEPENDS=	gupnp-av>=0.5.5:net/gupnp-av
AV_TOOLS_LIB_DEPENDS=	libgupnp-av-1.0.so:net/gupnp-av

.include <bsd.port.mk>
