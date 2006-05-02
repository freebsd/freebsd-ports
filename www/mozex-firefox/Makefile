# Ports collection makefile for:  mozex-firefox
# Date created:			  Tue Oct 28, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mozex
PORTVERSION=	1.9.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mozex allows Firefox's users to use external programs for mail, news, etc.

XPI_ID=		{01bc0112-afff-4fb5-8772-191bf35a8ffb}
XPI_FILES=	chrome/mozex.jar install.js install.rdf chrome.manifest
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
