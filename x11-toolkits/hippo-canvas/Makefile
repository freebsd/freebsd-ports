# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	hippo-canvas
PORTVERSION=	0.3.0
PORTREVISION=	5
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

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk20 glib20 pygtk2 pango
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--disable-gtk-doc
NO_STAGE=	yes
pre-configure:
	${REINPLACE_CMD} -e 's/^SUBDIRS =.*$$/SUBDIRS = ./g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
