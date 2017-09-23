# Created by: Dominic Fandrey <kamikaze@bsdforen.de>
# $FreeBSD$

PORTNAME=	live_http_headers
PORTVERSION=	0.17
DISTVERSIONSUFFIX=	-fx+sm
PORTREVISION=	3
CATEGORIES=	www
PKGNAMEPREFIX=	xpi-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Firefox extension to view HTTP headers

XPI_NUM=	3829
XPI_ID=		{8f8fe09b-0bd3-4470-bc1b-8cad42b8203a}

XPI_FILES=	TODO.txt \
		chrome/icons/default/LiveHTTPHeaders.ico \
		chrome/icons/default/LiveHTTPHeaders.xpm \
		chrome/livehttpheaders.jar \
		chrome.manifest \
		components/nsHeaderInfo.js \
		defaults/preferences/prefs.js \
		install.js \
		install.rdf

XPI_DIRS=	chrome/icons/default \
		chrome/icons \
		chrome \
		components \
		defaults/preferences \
		defaults

USES=		dos2unix
DOS2UNIX_REGEX=	.*\.(js|rdf|txt)

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -exec ${RM} \{} \;

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
