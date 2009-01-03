# New ports collection makefile for:	xpi-num2web
# Date created:		5 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	num2web
PORTVERSION=	0.1
CATEGORIES=	www
MASTER_SITES=	http://www.e164.org/${PORTNAME}/ CENKES

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Enum lookups support

XPI_ID=		support@e164.org
XPI_FILES=	components/num2web.js contents.rdf install.rdf chrome.manifest
XPI_DIRS=	components

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
