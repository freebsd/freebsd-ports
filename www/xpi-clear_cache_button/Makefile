# Created by: Barbara Guida <bar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clear_cache_button
PORTVERSION=	0.9f
DISTVERSIONSUFFIX=	-fx
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Adds a button to the toolbar that clears the browser cache

USE_XPI=	*firefox*

SUB_FILES=	pkg-message

XPI_ID=		{563e4790-7e70-11da-a72b-0800200c9a66}
XPI_NUM=	1801
XPI_FILES=	chrome/content/options.js \
		chrome/content/options.xul \
		chrome/content/overlay.js \
		chrome/content/overlay.xul \
		chrome/locale/en-US/clearcache.properties \
		chrome/locale/en-US/overlay.dtd \
		chrome/skin/classic/logo_16.png \
		chrome/skin/classic/logo_24.png \
		chrome/skin/classic/logo_32.png \
		chrome/skin/classic/overlay.css \
		chrome.manifest \
		install.rdf

XPI_DIRS=	chrome/skin/classic chrome/skin \
		chrome/locale/en-US chrome/locale \
		chrome/content \
		chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"

post-patch:
	@${REINPLACE_CMD} -e 's|<em:maxVersion>6\.\*<|<em:maxVersion>99.*<|' \
		${WRKSRC}/install.rdf

pre-install:
	@${RM} ${WRKSRC}/install.rdf.bak

.include <bsd.port.mk>
