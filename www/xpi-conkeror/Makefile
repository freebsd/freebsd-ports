# New ports collection makefile for:	conkeror
# Date created:		27 April 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	conkeror
PORTVERSION=	0.30
DISTVERSIONPREFIX=	firefox-
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX?=

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A completely keyboard driven browser based on firefox

RUN_DEPENDS=	${CONK_APP}:${PORTSDIR}/www/${CONK_APP}

CONK_ARGS=	-chrome chrome://conkeror/content
CONK_APP?=	${PKGNAMEPREFIX}firefox
CONK_EXEC?=	${PKGNAMEPREFIX}${PORTNAME}
PLIST_FILES=	bin/${CONK_EXEC}
XPI_ID=		{a79fe89b-6662-4ff4-8e88-09950ad4dfde}
XPI_FILES=	chrome/conkeror.jar components/nsCrank.js install.rdf chrome.manifest
XPI_DIRS=	chrome components

post-install:
	@${ECHO_CMD} exec `${WHICH} ${CONK_APP}` ${CONK_ARGS} > ${PREFIX}/bin/${CONK_EXEC}
	@${CHMOD} 555 ${PREFIX}/bin/${CONK_EXEC}

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
