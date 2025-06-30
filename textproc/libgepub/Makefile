PORTNAME=	libgepub
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject based library for handling and rendering epub documents
WWW=		https://gitlab.gnome.org/GNOME/libgepub

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3

USES=		compiler:c11 gettext-runtime gnome libarchive meson \
		pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2

MESON_ARGS=	-Dwidget=false

.include <bsd.port.mk>
