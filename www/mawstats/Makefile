# New ports collection makefile for:    mawstats
# Date created:                         Mon Apr 26 19:03:51 CEST 2010
# Whom:                                 Frank Wall <fw@moov.de>
#
# $FreeBSD$
#

PORTNAME=	mawstats
DISTVERSION=	0.8
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	fw@moov.de
COMMENT=	MAWStats is a Free Web Site Statistics tool

RUN_DEPENDS=	awstats>=6.8:${PORTSDIR}/www/awstats

NO_BUILD=	yes
USE_PHP=	yes
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
