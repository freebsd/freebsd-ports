# New ports collection makefile for:	xpi-twitterfox
# Date created:		14 Dezember 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twitterfox
PORTVERSION=	1.7.7
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	twitterFox firefox plugin.

XPI_NUM=	5081
XPI_ID=		twitternotifier@naan.net
XPI_FILES=	chrome/TwitterFox.jar chrome.manifest components/nsITwitterNotifier.xpt \
		components/nsTwitterNotifier.js defaults/preferences/twitternotifier.js \
		install.rdf
XPI_DIRS=	chrome components defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
