# New ports collection makefile for:	xpi-vimperator
# Date created:		14 April 2007
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	vimperator
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Vim look and feel for Firefox

XPI_ID=		{f9570b26-e246-4753-9b68-61aa95994237}
XPI_FILES=	chrome/vimperator.jar chrome.manifest install.rdf TODO
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
