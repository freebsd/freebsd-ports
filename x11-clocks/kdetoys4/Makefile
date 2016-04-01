# $FreeBSD$

PORTNAME=	kdetoys
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11-clocks kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE miscellaneous applications (meta port)

USE_KDE4=	kdeprefix
USES=		metaport

OPTIONS_DEFINE=	AMOR KTEATIME KTUX
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

AMOR_DESC=		Small animation which sits on top of active window
AMOR_RUN_DEPENDS=	${KDE4_PREFIX}/bin/amor:x11-clocks/amor

KTEATIME_DESC=		Handy timer for steeping tea
KTEATIME_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kteatime:x11-clocks/kteatime

KTUX_DESC=		Tux-in-a-Spaceship screen saver
KTUX_RUN_DEPENDS=	${KDE4_PREFIX}/bin/ktux:x11-clocks/ktux

.include <bsd.port.mk>
