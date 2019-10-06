# $FreeBSD$

PORTNAME=	gtk-layer-shell
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	x11-toolkits

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ library for the Wayland layer-shell protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	gtk30 introspection:build
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	wmww

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

EXAMPLES_MESON_TRUE=	examples

.include <bsd.port.mk>
