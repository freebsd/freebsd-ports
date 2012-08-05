# New ports collection makefile for:	forecastfox
# Date created:		2006-05-15
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	forecastfox
PORTVERSION=	2.2.1
DISTVERSIONSUFFIX=	-fx+sm
CATEGORIES=	www

MAINTAINER=	simon@olofsson.de
COMMENT=	Get international weather forecasts and display them

XPI_DISTNAME=	${PORTNAME}_weather
XPI_ID=		{0538E3E3-7E9B-4d49-8831-A227C80A7AD3}
XPI_NUM=	398
XPI_FILES=	chrome/forecastfox.jar chrome.manifest icon.png install.rdf
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
