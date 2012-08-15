# New ports collection makefile for:	xpi-it_s_all_text
# Date created:				2009-04-26
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	it_s_all_text
PORTVERSION=	1.6.0
DISTVERSIONSUFFIX=	-sm+fx
CATEGORIES=	www
DISTNAME=	${PORTNAME:S/it_s/its/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Edit textareas using an external editor

XPI_NUM=	4125
XPI_ID=		itsalltext@docwhat.gerf.org
XPI_FILES=	chrome.manifest \
		chrome/content.jar chrome/da-DK.jar \
		chrome/de-DE.jar chrome/en-US.jar \
		chrome/es-ES.jar chrome/fr-FR.jar \
		chrome/it-IT.jar chrome/ja-JP.jar \
		chrome/nl-NL.jar chrome/pl-PL.jar \
		chrome/pt-BR.jar chrome/sk-SK.jar \
		chrome/zh-CN.jar chrome/zh-TW.jar \
		defaults/preferences/itsalltext.js \
		gpl.txt install.rdf
XPI_DIRS=	chrome \
		defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
