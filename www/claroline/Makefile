# New ports collection makefile for:	claroline
# Date created:		29 Feb 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	claroline
PORTVERSION=	1.8.9
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	claroline189

MAINTAINER=	wenheping@gmail.com
COMMENT=	Open Source eLearning and eWorking platform

NO_BUILD=	yes
USE_PHP=	mysql
WRKSRC=		${WRKDIR}/${DISTNAME}
PORTDOCS=	INSTALL.txt README.txt
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "claroline index.php" ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' >>${TMPPLIST}

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
