# Ports collection Makefile for:	firefox-flp
# Date created:				Sat Feb 21, 2004
# Whom:					Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	firefox-flp
PORTVERSION=	1.5.0.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	firefox/releases/${PORTVERSION}/linux-i686/xpi
DISTNAME=	fr

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Firefox French Language Pack (FLP)

XPI_ID=		langpack-fr@firefox.mozilla.org
XPI_FILES=	chrome/chromelist.txt chrome/fr.jar chrome.manifest install.rdf
XPI_DIRS=	chrome

.include "${.CURDIR}/../../www/xpi-adblock/Makefile.xpi"

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
