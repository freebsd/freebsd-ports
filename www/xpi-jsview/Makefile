# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsview
PORTVERSION=	2.0.8
DISTVERSIONSUFFIX=	-fx+sm
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Easily view embedded/external JS and CSS

LICENSE=	GPLv2

USE_XPI=	*firefox*

XPI_ID=		{cf15270e-cf08-4def-b4ea-6a5ac23f3bca}
XPI_NUM=	2076
XPI_FILES=	chrome/jsview.jar chrome.manifest defaults/preferences/jsview.js install.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

post-patch:
	@${REINPLACE_CMD} -e 's|<em:maxVersion>9\.0a1<|<em:maxVersion>99.*<|' ${WRKSRC}/install.rdf

pre-install:
	@${RM} ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
