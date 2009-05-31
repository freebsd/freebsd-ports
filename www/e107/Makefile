# New ports collection makefile for:	e107
# Date created:				31 May, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	e107
PORTVERSION=	0.7.15
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_v${PORTVERSION}_full

MAINTAINER=	wenheping@gmail.com
COMMENT=	A content management system written in PHP

USE_PHP=	mysql xml
WRKSRC=		${WRKDIR}/e107

.include <bsd.port.pre.mk>

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	E107DIR=${E107DIR}
E107DIR=	www/e107

post-extract:
	@cd ${WRKDIR} && ${MKDIR} ${WRKSRC}
	@cd ${WRKDIR} && ${MV} *.php ${WRKSRC}
	@cd ${WRKDIR} && ${MV} e107_* ${WRKSRC}
	@cd ${WRKDIR} && ${MV} e107.htaccess ${WRKSRC}
	@cd ${WRKDIR} && ${MV} favicon.ico ${WRKSRC}
	@cd ${WRKDIR} && ${MV} robots.txt ${WRKSRC}

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s#${WRKSRC}#${E107DIR}#g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d | ${SED} "s#${WRKSRC}#@dirrm ${E107DIR}#g" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
