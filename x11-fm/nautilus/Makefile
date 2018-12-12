# Created by: ade, archie
# $FreeBSD$

PORTNAME=	nautilus
PORTVERSION=	3.28.1
PORTREVISION=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgnome-autoar-0.so:archivers/gnome-autoar \
		libgexiv2.so:graphics/gexiv2 \
		libtracker-sparql-2.0.so:sysutils/tracker

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome \
		localbase meson pkgconfig python:3.4+,build tar:xz
#USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 introspection:build
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3
USE_LDCONFIG=	yes
USE_XORG=	x11
MESON_ARGS=	-Denable-packagekit=false \
		-Denable-selinux=false
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

.include <bsd.port.mk>
