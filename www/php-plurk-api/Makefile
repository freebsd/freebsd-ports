# New ports collection makefile for:	php-plurk-api
# Date created:		2010-02-26
# Whom:			Bo-Yi Wu <appleboy.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	php-plurk-api
PORTVERSION=	1.4.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	php-plurk-api-${PORTVERSION}

MAINTAINER=	appleboy.tw@gmail.com
COMMENT=	A Plurk API Implementation with PHP

USE_ZIP=	yes
NO_BUILD=	yes
USE_PHP=	json curl

WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-install:
	@${MV} ${WRKSRC}\ ${PORTVERSION} ${WRKSRC}
	@${ECHO_CMD} '@exec ${MV} ${WRKSRC}\ ${PORTVERSION} \
		${WRKSRC}' >> ${TMPPLIST}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${PHPBBDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}
	@${CHMOD} 755 ${WWWDIR}/example.php
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${WWWDIR}/example.php' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
