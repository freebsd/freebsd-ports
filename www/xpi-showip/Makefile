# New ports collection makefile for:	xpi-showip
# Date created:				10 November 2011
# Whom:					Barbara <barbara.xxx1975@libero.it>
#
# $FreeBSD$
#

PORTNAME=	showip
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	barbara.xxx1975@libero.it
COMMENT=	Show the IP address of the current page in the status bar

LICENSE=	GPLv2

PROJECTHOST=	firefox-showip

USE_XPI=	*firefox*
XPI_ID=		{3e9bb2a7-62ca-4efa-a4e6-f6f6168a652d}
XPI_NUM=	590
XPI_FILES=	chrome/ipv6ident.jar \
		COPYING \
		chrome.manifest \
		install.rdf \
		install.js

XPI_DIRS=	chrome

post-patch:
	@${REINPLACE_CMD} -e 's|<em:maxVersion>5\.\*<|<em:maxVersion>99.*<|' \
	    ${WRKSRC}/install.rdf

pre-install:
	@${RM} -f ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
