# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	hippo-canvas
PORTVERSION=	0.3.0
PORTREVISION=	7
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Client stacker popup widget for GTK+ toolkit

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR}
LIB_DEPENDS=	libcroco-0.6.so:textproc/libcroco
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR}

USES=		gmake libtool pathfix pkgconfig python:2.7 tar:bzip2
USE_GNOME=	cairo gtk20 glib20 librsvg2 pygtk2 pango
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc --enable-python
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e 's/^SUBDIRS =.*$$/SUBDIRS = ./g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
