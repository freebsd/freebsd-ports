# $FreeBSD$

PORTNAME=	oxygen
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	KDE/stable/${PORTNAME}-gtk3/${PORTVERSION}/src
PKGNAMEPREFIX=	gtk3-
PKGNAMESUFFIX=	-engine
DISTNAME=	${PORTNAME}-gtk3-${PORTVERSION}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Oxygen GTK+ 3 engine and theme

LICENSE=	LGPL21

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libdbus-glib-1.so:devel/dbus-glib

USE_GNOME=	gtk30
USES=		cmake:outsource pkgconfig tar:bzip2

.include <bsd.port.mk>
