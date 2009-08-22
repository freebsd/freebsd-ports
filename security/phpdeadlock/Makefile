# New ports collection makefile for:	phpdeadlock
# Date created:		08 Oct 2007
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phpdeadlock
PORTVERSION=	1.01
CATEGORIES=	security www
MASTER_SITES=	SF/${PORTNAME}/Deadlock/${PORTVERSION}%20Stable
DISTNAME=	Deadlock-${PORTVERSION}-Stable

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Web-based user authentication/password protection system

WRKSRC=	${WRKDIR}/Deadlock-1.01
DLURL?=	${PORTNAME}
DLDIR=		www/${DLURL}
PORTDOCS=	CHANGES.txt COPYING.txt UPGRADE.txt

USE_DOS2UNIX=	yes
USE_APACHE=	1.3+
USE_PHP=	mysql session ctype pcre
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	DLURL=${DLURL} DLDIR=${DLDIR}

post-extract:
	@cd ${WRKDIR} && ${MV} "Deadlock v1.01" Deadlock-1.01

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -exec ${RM} {} \;

do-install:
	@cd ${WRKSRC}/deadlock && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${CHMOD} 777 ${WWWDIR}/db_config.php
	@${ECHO_CMD} '@exec ${CHMOD} 777 \
		${WWWDIR:S|^${PREFIX}/|%D/|}/db_config.php' >> ${TMPPLIST}

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
