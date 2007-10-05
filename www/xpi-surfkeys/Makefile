# New ports collection makefile for:	xpi-surfkeys
# Date created:		2006-07-15
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	surfkeys
DISTVERSION=	0_4_2
CATEGORIES=	www
MASTER_SITES=	MOZDEV
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	simon@olofsson.de
COMMENT=	Comfortable surfing with keyboard

DEPRECATED=	Development has been ceased
EXPIRATION_DATE=	2007-12-01

XPI_ID=		{a44ef047-cd8d-406e-a354-b7101bd24735}
XPI_FILES=	chrome/chrome.jar chrome.manifest defaults/preferences/prefs.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
