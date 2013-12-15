# $FreeBSD$

PORTNAME=	oxygen
PORTVERSION=	1.2.1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-gtk3/${PORTVERSION}/src
PKGNAMEPREFIX=	gtk3-
PKGNAMESUFFIX=	-engine
DISTNAME=	${PORTNAME}-gtk3-${PORTVERSION}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Oxygen GTK+ 3 engine and theme

LICENSE=	LGPL21

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
USE_GNOME=	gtk30
USES=		cmake:outsource pkgconfig

.include <bsd.port.mk>
