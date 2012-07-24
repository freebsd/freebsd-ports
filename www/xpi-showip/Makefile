# New ports collection makefile for:	xpi-showip
# Date created:				10 November 2011
# Whom:					Barbara <barbara.xxx1975@libero.it>
#
# $FreeBSD$
#

PORTNAME=	showip
PORTVERSION=	1.8.1
DISTVERSIONSUFFIX=	-tb+sm+fx
CATEGORIES=	www

MAINTAINER=	barbara.xxx1975@libero.it
COMMENT=	Show the IP address of the current page in the status bar

LICENSE=	GPLv2

XPI_NUM=	590
XPI_ID=		{3e9bb2a7-62ca-4efa-a4e6-f6f6168a652d}

post-patch:
	@${REINPLACE_CMD} -e 's|<em:maxVersion>14\.\*<|<em:maxVersion>99.*<|; \
		s|<em:maxVersion>2\.11\.\*<|<em:maxVersion>99.99.*<|' \
	    ${WRKSRC}/install.rdf

pre-install:
	@${RM} -f ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
