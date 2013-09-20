# Created by: Frank Wall <fw@moov.de>
# $FreeBSD$

PORTNAME=	mawstats
DISTVERSION=	0.8
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	fw@moov.de
COMMENT=	MAWStats is a Free Web Site Statistics tool

RUN_DEPENDS=	awstats>=6.8:${PORTSDIR}/www/awstats

DEPRECATED=	Upstream development dead, use www/[j]awstats instead
EXPIRATION_DATE=2014-01-01

NO_BUILD=	yes
USE_PHP=	yes
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
do-install:
	${MKDIR} ${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
