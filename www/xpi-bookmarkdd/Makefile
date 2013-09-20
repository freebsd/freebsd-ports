# Created by: Gustavo Fukao <gustavofukao@gmail.com>
# $FreeBSD$

PORTNAME=	bookmarkdd
PORTVERSION=	0.7.5
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	gustavofukao@gmail.com
COMMENT=	Detects duplicates when bookmarks are added

XPI_ID=		{ba243cb0-b824-4a26-9418-73ee795d9b9d}
XPI_NUM=	1553
XPI_DISTNAME=	bookmark_duplicate_detector
XPI_FILES=	chrome.manifest install.rdf \
		chrome/ChangeLog chrome/Todo chrome/duplicates.jar \
		defaults/preferences/prefs.js
XPI_DIRS=	chrome defaults/preferences defaults

NO_STAGE=	yes
.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
