# New ports collection makefile for:	xpi-downthemall
# Date created:		19 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	downthemall
PORTVERSION=	0.9.9.10
DISTVERSIONSUFFIX=	-fx+tb+fl
CATEGORIES=	www

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Lets you download all the links in a webpage and much more

XPI_DISTNAME=	downthemall!
WRKSRC=		${WRKDIR}/${DISTNAME:S/!/_/}
XPI_ID=		{DDC359D1-844A-42a7-9AA1-88A850A938A8}
XPI_NUM=	201
XPI_FILES=	chrome/dta.jar chrome.manifest components/privacycontrol.js \
		defaults/preferences/privacycontrol.js gpl.txt install.rdf notice.txt
XPI_DIRS=	chrome components defaults/preferences defaults

post-extract:
	@${FIND} ${WRKSRC} -name .svn|${XARGS} ${RM} -rf

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
