# New ports collection makefile for:	atutor
# Date created:		11 Feb 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	atutor
PORTVERSION=	1.6
CATEGORIES=	www
MASTER_SITES=	http://superb-west.dl.sourceforge.net/sourceforge/atutor/
DISTNAME=	ATutor-${DISTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	An Open Source Web-based Learning Content Management System (LCMS)

USE_PHP=	session mbstring zlib mysql
WRKSRC=		${WRKDIR}/ATutor

.include <bsd.port.pre.mk>

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	ATUTDIR=${ATUTDIR} \
		ATUTDATDIR=${ATUTDATDIR}

ATUTDIR?=	www/atutor
ATUTDATDIR?=	${ATUTDIR}/content
ATUTCONFIG?=	include/config.inc.php

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${ATUTDIR}?g" >${PLIST}
	@${ECHO_CMD} @dirrm ${ATUTDATDIR} >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${ATUTDIR}?g" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/${ATUTDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${ATUTDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${PREFIX}/${ATUTDIR}' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${ATUTDIR} -type d -exec ${CHMOD} a+x {} \;
	@${INSTALL} -d ${PREFIX}/${ATUTDATDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${ATUTDATDIR}
	@${ECHO_CMD} '@exec ${INSTALL} -d \
		${PREFIX}/${ATUTDATDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${PREFIX}/${ATUTDATDIR}' >> ${TMPPLIST}
	@${CHMOD} 755 ${PREFIX}/${ATUTDATDIR}
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${PREFIX}/${ATUTDATDIR}' >> ${TMPPLIST}
	@${CHMOD} 666 ${PREFIX}/${ATUTDIR}/${ATUTCONFIG}
	@${ECHO_CMD} '@exec ${CHMOD} 666 \
		${PREFIX}/${ATUTDIR}/${ATUTCONFIG}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${INSTALL} -d \
		${PREFIX}/${ATUTDIR}/themes/blumin/users' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${INSTALL} -d \
		${PREFIX}/${ATUTDIR}/themes/greenmin/users' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
