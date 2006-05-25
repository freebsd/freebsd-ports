# Ports collection makefile for:	preferential-firefox
# Date created:				Tue Oct 28, 2003
# Whom:					Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	preferential
PORTVERSION=	0.8.1
DISTVERSIONSUFFIX=	-fx+mz+tb
CATEGORIES=	www

MAINTAINER=	simon@olofsson.de
COMMENT=	Advanced preferences manager for Mozilla-based products

XPI_DISTNAME=	preferential_new_guid_
XPI_ID=		{e3a1bec3-1cc1-4d20-875b-a10587471a5e}
XPI_FILES=	chrome/preferential.jar install.js install.rdf chrome.manifest
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
