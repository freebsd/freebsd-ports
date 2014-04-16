# Created by: Olivier Duchateau <olivierd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lasem
PORTVERSION=	0.4.1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SVG/Mathml renderer and editor

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/stix:${PORTSDIR}/x11-fonts/stix-fonts

USES=	tar:xz pkgconfig pathfix gmake gettext
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 pango intltool gdkpixbuf2 libxml2 introspection:build

CONFIGURE_ARGS=	--disable-gtk-doc-html \
	--without-html-dir

.include <bsd.port.mk>
