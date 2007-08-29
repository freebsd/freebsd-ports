# New ports collection makefile for:	xpi-vimperator
# Date created:		14 April 2007
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	vimperator
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Vim look and feel for Firefox

XPI_ID=		vimperator@mozdev.org
XPI_FILES=	AUTHORS ChangeLog Donators Makefile TODO chrome/vimperator.jar\
		chrome.manifest install.rdf
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
