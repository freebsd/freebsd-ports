PORTNAME=	nautilus-python
DISTVERSION=	4.1.0
CATEGORIES=	x11-fm gnome python
MASTER_SITES=	GNOME

MAINTAINER=	daniel@shafer.cc
COMMENT=	Python bindings for the Nautilus extension framework
WWW=		https://gitlab.gnome.org/GNOME/nautilus-python

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome localbase meson pkgconfig python tar:xz
USE_GNOME=	glib20 nautilus4 pygobject3
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_DEFINE=	GTKDOC
OPTIONS_SUB=	yes

GTKDOC_MESON_ENABLED=		docs
GTKDOC_DESC=			Build documentation
GTKDOC_BUILD_DEPENDS=		gtkdoc-scan:textproc/gtk-doc

.include <bsd.port.mk>
