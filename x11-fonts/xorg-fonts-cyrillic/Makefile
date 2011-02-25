# New ports collection makefile for:    xorg-fonts-cyrillic
# Date created:		30 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-fonts-cyrillic
PORTVERSION=	7.5.1
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org Cyrillic bitmap fonts

RUN_DEPENDS=	${FONTDIR}/cyrillic/crox1c.pcf.gz:${PORTSDIR}/x11-fonts/font-cronyx-cyrillic \
		${FONTDIR}/cyrillic/koi12x24.pcf.gz:${PORTSDIR}/x11-fonts/font-misc-cyrillic \
		${FONTDIR}/cyrillic/screen8x16.pcf.gz:${PORTSDIR}/x11-fonts/font-screen-cyrillic \
		${FONTDIR}/cyrillic/proof9x16.pcf.gz:${PORTSDIR}/x11-fonts/font-winitzki-cyrillic \
		${FONTDIR}/encodings/encodings.dir:${PORTSDIR}/x11-fonts/encodings

CONFLICTS=	XFree86-fontCyrillic-*

NO_BUILD=	# none
FONTDIR=	${LOCALBASE}/lib/X11/fonts

do-install:	# empty

.include <bsd.port.mk>
