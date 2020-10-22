# $FreeBSD$

PORTNAME=	gtk-layer-shell
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	x11-toolkits

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ library for the Wayland layer-shell protocol

LICENSE=	LGPL3+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LICENSE_LGPL.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE_MIT.txt

BUILD_DEPENDS=	wayland-protocols>=1.16:graphics/wayland-protocols
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
