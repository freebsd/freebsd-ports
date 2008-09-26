# New ports collection makefile for:	xpi-neo-diggler
# Date created:		12 May 2008
# Whom:			Harald Schmalzbauer <h.schmalzbauer@omnisec.de>
#
# $FreeBSD$
#

PORTNAME=	neo-diggler
PORTVERSION=	1.0.6
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	freebsd@omnilan.de
COMMENT=	URL-related actions through menu button

XPI_DISTNAME=	neo_diggler
XPI_ID=		{9b84cce7-a817-45d7-865e-9e6e8da1c388}
XPI_NUM=	3763
XPI_FILES=	chrome.manifest install.rdf \
		chrome/diggler.jar defaults/preferences/diggler.js
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
