PORTNAME=	libdazzle
DISTVERSION=	3.44.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Companion library to GObject and Gtk+
WWW=		https://gitlab.gnome.org/GNOME/libdazzle

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build

.include <bsd.port.mk>
