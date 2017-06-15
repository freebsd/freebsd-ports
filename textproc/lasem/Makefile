# Created by: Olivier Duchateau <olivierd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lasem
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SVG/Mathml renderer and editor

LICENSE=	GPLv2

RUN_DEPENDS=	stixfonts>0:x11-fonts/stix-fonts

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 pango intltool gdkpixbuf2 libxml2 introspection:build

CONFIGURE_ARGS=	--disable-gtk-doc-html \
	--without-html-dir

.include <bsd.port.mk>
