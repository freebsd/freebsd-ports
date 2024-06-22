PORTNAME=	libgepub
PORTVERSION=	0.7.1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject based library for handling and rendering epub documents

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwebkit2gtk-4.1.so:www/webkit2-gtk3 \
		libsoup-3.0.so:devel/libsoup3

USES=		compiler:c11 gettext-runtime gnome libarchive meson pkgconfig \
		tar:xz
USE_GNOME=	gtk30 introspection:build libxml2

.include <bsd.port.mk>
