# New ports collection makefile for:	xpi-autobrowse
# Date created:		20 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autobrowse
PORTVERSION=	0.7
DISTVERSIONSUFFIX=	-fx+fl
CATEGORIES=	www
MASTER_SITES=	BERLIOS CENKES

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Surfs the net for you

XPI_ID=		{3867e8ff-5171-4346-a578-b118c968c65c}
XPI_FILES=	chrome/autobrowse.jar chrome.manifest defaults/preferences/settings.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
