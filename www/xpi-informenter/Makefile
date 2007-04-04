# New ports collection makefile for:	xpi-informenter
# Date created:		14 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	informenter
PORTVERSION=	0.5.3
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Helps fill forms out

XPI_ID=		{5546F97E-11A5-46b0-9082-32AD74AAA920}
XPI_FILES=	chrome/informenter.jar defaults/preferences/informenter.js install.rdf chrome.manifest
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
