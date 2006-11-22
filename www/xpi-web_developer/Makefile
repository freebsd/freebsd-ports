# New ports collection makefile for:	xpi-web_developer
# Date created:			2006/05/06
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	web_developer
PORTVERSION=	1.0.2
PORTREVISION=	1
DISTVERSIONSUFFIX=	-fx+fl
CATEGORIES=	www

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	An extension to add various web developer tools

XPI_ID=		{c45c406e-ab73-11d8-be73-000a95be3b12}
XPI_FILES=	chrome/webdeveloper.jar chrome.manifest install.js \
		install.rdf license.txt
XPI_DIRS=	chrome

post-patch:
	@${REINPLACE_CMD} -i '' -e '/13a3a9e97384/n;s|1\.5\.0\.\*|2.0.0.*|' ${WRKSRC}/install.rdf

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
