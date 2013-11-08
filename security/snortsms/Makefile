# Created by: J Randolph <snortsms@servangle.net>
# $FreeBSD$

PORTNAME=	snortsms
PORTVERSION=	1.7.8
CATEGORIES=	security www
MASTER_SITES=	SF/${PORTNAME}/SnortSMS%20Suite%20%28Console_Agent%29/${PORTVERSION}-Release

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A remote management and monitoring interface for Snort based IDS

DEPRECATED=	Not active since several years.
EXPIRATION_DATE=	2013-12-08

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB \
		${LOCALBASE}/bin/curl:${PORTSDIR}/ftp/curl

USE_PHP=	mysql pcre pcntl session curl
NO_BUILD=	yes

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} \
		WRKSRC=${WRKSRC} \
		PORTSDIR=${PORTSDIR}

NO_STAGE=	yes
do-install:
	${MKDIR} ${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR})
	${CHMOD} 775 ${WWWDIR}/conf
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
