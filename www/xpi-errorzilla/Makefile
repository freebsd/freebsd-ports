# New ports collection makefile for:	xpi-errorzilla
# Date created:		02 Nov 2006
# Whom:			Steven Kreuzer <skreuzer@f2o.org>
#
# $FreeBSD$
#

PORTNAME=	errorzilla
PORTVERSION=	0.2
DISTVERSIONSUFFIX=	-fx+fl
CATEGORIES=	www

MAINTAINER=	skreuzer@f2o.org
COMMENT=	Useful error pages

XPI_DISTNAME=	errorzilla_mod
XPI_ID=		ErrorZillaMod@jaybaldwin
XPI_FILES=	chrome/errorzillamod.jar chrome.manifest install.rdf license.txt
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
