# $FreeBSD$

PORTNAME=	breeze-gtk
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Breeze visual style for Gtk

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake compiler:c++11-lang cpe kde:5 pkgconfig qt:5 \
		tar:xz
USE_GNOME=	gdkpixbuf2
USE_KDE=	ecm
USE_QT=		core buildtools_build qmake_build

.include <bsd.port.mk>
