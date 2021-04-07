PORTNAME=	oxygen
PORTVERSION=	1.4.6
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	KDE/stable/${PORTNAME}-gtk2/${PORTVERSION}/src
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine
DISTNAME=	${PORTNAME}-gtk2-${PORTVERSION}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Oxygen-Gtk engine and theme

LICENSE=	LGPL21

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libdbus-glib-1.so:devel/dbus-glib

USES=		cmake compiler:c++11-lang gnome pkgconfig tar:bzip2
USE_GNOME=	gtk20

.include <bsd.port.mk>
