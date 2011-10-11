# New ports collection makefile for:	R-cran-scrapeR
# Date created:		2011-08-28
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scrapeR
PORTVERSION=	0.1.6
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for Scraping Data from HTML and XML Documents

RUN_DEPENDS=	R-cran-XML>0:${PORTSDIR}/textproc/R-cran-XML \
		R-cran-RCurl>0:${PORTSDIR}/ftp/R-cran-RCurl

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
