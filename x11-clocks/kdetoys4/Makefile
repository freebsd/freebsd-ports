# $FreeBSD$

PORTNAME=	kdetoys
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-clocks kde
DISTFILES=	#

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE miscellaneous applications (meta port)

USE_KDE4=	kdeprefix
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	AMOR KTEATIME KTUX
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

AMOR_DESC=		Small animation which sits on top of active window
AMOR_RUN_DEPENDS=	${KDE4_PREFIX}/bin/amor:${PORTSDIR}/x11-clocks/amor

KTEATIME_DESC=		Handy timer for steeping tea
KTEATIME_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kteatime:${PORTSDIR}/x11-clocks/kteatime

KTUX_DESC=		Tux-in-a-Spaceship screen saver
KTUX_RUN_DEPENDS=	${KDE4_PREFIX}/bin/ktux:${PORTSDIR}/x11-clocks/ktux

.include <bsd.port.mk>
