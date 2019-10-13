# $FreeBSD$

PORTNAME=	breeze-gtk
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Breeze visual style for Gtk

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		sassc:textproc/sassc
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR}

USES=		cmake compiler:c++11-lang cpe gnome kde:5 pkgconfig \
		python:3.4+ qt:5 tar:xz
USE_GNOME=	gdkpixbuf2
USE_KDE=	breeze ecm
USE_QT=		core buildtools_build qmake_build

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
