# Created by: Olivier Duchateau <olivierd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lasem
PORTVERSION=	0.5.1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SVG/Mathml renderer and editor

OPTIONS_DEFINE=	DOCS

LICENSE=	GPLv2

RUN_DEPENDS=	stixfonts>0:x11-fonts/stix-fonts

GNU_CONFIGURE=	yes
USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	glib20 pango intltool gdkpixbuf2 libxml2 introspection:build

CONFIGURE_ARGS=	--disable-gtk-doc-html \
	--without-html-dir
INSTALL_TARGET=	install-strip
MAKE_ARGS=	lasemdocdir=${DOCSDIR}

.include <bsd.port.mk>
