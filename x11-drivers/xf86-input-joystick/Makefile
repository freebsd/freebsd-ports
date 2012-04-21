# New ports collection makefile for:	xf86-input-joystick
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-input-joystick
PORTVERSION=	${JOYVER}
PORTREVISION=	${JOYREVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org joystick input driver

XORG_CAT=	driver
USE_XORG=	xextproto videoproto
MAN4=		joystick.4x

.if defined(WITH_NEW_XORG)
JOYVER=		1.6.0
JOYREVISION=	0
.else
JOYVER=		1.5.0
JOYREVISION=	1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
