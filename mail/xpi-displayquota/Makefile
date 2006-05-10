# New ports collection makefile for:	xpi-displayquota
# Date created:			10 May 2006
# Whom:				Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	displayquota
PORTVERSION=	0.1.10
DISTVERSIONSUFFIX=	-tb
CATEGORIES=	mail

MAINTAINER=	alex@foxybanana.com
COMMENT=	An extension that displays your IMAP quota in statusbar

XPI_DISTNAME=	display_quota
XPI_ID=		{c1ac4523-76c2-9995-adbd-d93bf5141bea}
XPI_FILES=	chrome/DisplayQuota.jar defaults/preferences/displayquota.js install.rdf chrome.manifest
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../../www/xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
