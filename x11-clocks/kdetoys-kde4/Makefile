# $FreeBSD$

PORTNAME=	kdetoys
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	x11-clocks kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE miscellaneous applications (meta port)

USES=		kde:4 metaport

OPTIONS_DEFINE=	AMOR KTEATIME KTUX
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

AMOR_DESC=		Small animation which sits on top of active window
AMOR_RUN_DEPENDS=	${KDE_PREFIX}/bin/amor:x11-clocks/amor-kde4

KTEATIME_DESC=		Handy timer for steeping tea
KTEATIME_RUN_DEPENDS=	${KDE_PREFIX}/bin/kteatime:x11-clocks/kteatime-kde4

KTUX_DESC=		Tux-in-a-Spaceship screen saver
KTUX_RUN_DEPENDS=	${KDE_PREFIX}/bin/ktux:x11-clocks/ktux-kde4

.include <bsd.port.mk>
