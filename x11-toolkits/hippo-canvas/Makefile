# New ports collection makefile for:	hippo-canvas
# Date created:		2008-05-27
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hippo-canvas
PORTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	A client stacker popup widget for GTK+ toolkit

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libcroco-0.6.pc:${PORTSDIR}/textproc/libcroco \
		${LOCALBASE}/libdata/pkgconfig/cairo.pc:${PORTSDIR}/graphics/cairo \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo
LIB_DEPENDS=	croco-0.6.3:${PORTSDIR}/textproc/libcroco \
		cairo.2:${PORTSDIR}/graphics/cairo \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk20 glib20 pygtk2 pango
USE_PYTHON=	2.5+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--disable-gtk-doc
pre-configure:
	${REINPLACE_CMD} -e 's/^SUBDIRS =.*$$/SUBDIRS = ./g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
