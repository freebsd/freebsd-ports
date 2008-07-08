# New ports collection makefile for:	hippo-canvas
# Date created:		2008-05-27
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hippo-canvas
PORTVERSION=	0.3.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	wahjava@gmail.com
COMMENT=	A client stacker popup widget for GTK+ toolkit

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libcroco-0.6.pc:${PORTSDIR}/textproc/libcroco \
		${LOCALBASE}/libdata/pkgconfig/cairo.pc:${PORTSDIR}/graphics/cairo \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo
LIB_DEPENDS=	croco-0.6.3:${PORTSDIR}/textproc/libcroco \
		cairo.2:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk20 glib20 pygtk2 pango
USE_PYTHON=	2.5+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--enable-gtk-doc
BUILD_DEPENDS+=	${LOCALBASE}/bin/gtkdocize:${PORTSDIR}/textproc/gtk-doc
.else
CONFIGURE_ARGS+=	--disable-gtk-doc
pre-configure:
	${REINPLACE_CMD} -e 's/^SUBDIRS =.*$$/SUBDIRS = ./g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
