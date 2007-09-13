# New ports collection makefile for:    xorg-fonts-75dpi
# Date created:		30 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-fonts-75dpi
PORTVERSION=	7.3
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org 75dpi bitmap fonts

RUN_DEPENDS=	${FONTDIR}/75dpi/courB08.pcf.gz:${PORTSDIR}/x11-fonts/font-adobe-75dpi \
		${FONTDIR}/75dpi/UTBI__10.pcf.gz:${PORTSDIR}/x11-fonts/font-adobe-utopia-75dpi \
		${FONTDIR}/75dpi/luBIS08.pcf.gz:${PORTSDIR}/x11-fonts/font-bh-75dpi \
		${FONTDIR}/75dpi/lutBS08.pcf.gz:${PORTSDIR}/x11-fonts/font-bh-lucidatypewriter-75dpi \
		${FONTDIR}/75dpi/charB08.pcf.gz:${PORTSDIR}/x11-fonts/font-bitstream-75dpi \
		${FONTDIR}/encodings/encodings.dir:${PORTSDIR}/x11-fonts/encodings

CONFLICTS=	XFree86-font75dpi-*

NO_BUILD=	# none
FONTDIR=	${X11BASE}/lib/X11/fonts

do-install:	# empty

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	is part of X.Org and you have ${X_WINDOW_SYSTEM} set for X11\
	distribution. See The X Window System and Virtual Consoles chapter\
	of FAQ for more information
.endif

.include <bsd.port.post.mk>
