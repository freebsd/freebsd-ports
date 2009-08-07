# New ports collection makefile for:	xpi-errorzilla
# Date created:		02 Nov 2006
# Whom:			Steven Kreuzer <skreuzer@exit2shell.com>
#
# $FreeBSD$
#

PORTNAME=	errorzilla
PORTVERSION=	0.39
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Useful error pages

XPI_DISTNAME=	errorzilla_mod
XPI_NUM=	3336
XPI_ID=	{ec8030f7-c20a-464f-9b0e-13a3a9e97384}
XPI_FILES=	chrome/errorzillamod.jar chrome.manifest defaults/preferences/prefs.js install.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
