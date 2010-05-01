# New ports collection makefile for:    xorg-fonts-type1
# Date created:		30 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-fonts-type1
PORTVERSION=	7.5
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org Type1 fonts

RUN_DEPENDS=	${FONTDIR}/Type1/UTBI____.afm:${PORTSDIR}/x11-fonts/font-adobe-utopia-type1 \
		${FONTDIR}/Type1/l047013t.afm:${PORTSDIR}/x11-fonts/font-bh-type1 \
		${FONTDIR}/Type1/c0419bt_.afm:${PORTSDIR}/x11-fonts/font-bitstream-type1 \
		${FONTDIR}/Type1/cour.afm:${PORTSDIR}/x11-fonts/font-ibm-type1 \
		${FONTDIR}/Type1/cursor.pfa:${PORTSDIR}/x11-fonts/font-xfree86-type1 \
		${FONTDIR}/encodings/encodings.dir:${PORTSDIR}/x11-fonts/encodings

CONFLICTS=	XFree86-fontScalable-*

do-install:	# empty

NO_BUILD=	# none
FONTDIR=	${LOCALBASE}/lib/X11/fonts

.include <bsd.port.mk>
