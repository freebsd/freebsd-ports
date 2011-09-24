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

DEPRECATED=	Development has been ceased and not compatible with Firefox > 3.
EXPIRATION_DATE=	2011-12-01

XPI_ID=		{01bc0112-afff-4fb5-8772-191bf35a8ffb}
XPI_FILES=	chrome/mozex.jar install.js install.rdf chrome.manifest
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
