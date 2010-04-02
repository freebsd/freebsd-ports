# Ports collection makefile for:	mozex-firefox
# Date created:				Tue Oct 28, 2003
# Whom:					Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mozex
PORTVERSION=	1.9.12
CATEGORIES=	www
MASTER_SITES=	MOZDEV

MAINTAINER=	simon@olofsson.de
COMMENT=	External commands integration

XPI_ID=		{01bc0112-afff-4fb5-8772-191bf35a8ffb}
XPI_FILES=	chrome/mozex.jar install.js install.rdf chrome.manifest
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
