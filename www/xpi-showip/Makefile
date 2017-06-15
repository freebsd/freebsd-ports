# Created by: Barbara Guida <bar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	showip
PORTVERSION=	2.0
DISTVERSIONSUFFIX=	-tb+fx+sm
CATEGORIES=	www

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Show the IP address of the current page in the status bar

LICENSE=	GPLv2

XPI_NUM=	590
XPI_ID=		{3e9bb2a7-62ca-4efa-a4e6-f6f6168a652d}

post-patch:
	@${REINPLACE_CMD} -e 's|<em:maxVersion>14\.\*<|<em:maxVersion>99.*<|; \
		s|<em:maxVersion>2\.11\.\*<|<em:maxVersion>99.99.*<|' \
	    ${WRKSRC}/install.rdf

pre-install:
	@${RM} ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
