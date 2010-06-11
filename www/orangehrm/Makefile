# New ports collection makefile for:	orangehrm
# Date created:				06 Dec, 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	orangehrm
PORTVERSION=	2.5.0.5
CATEGORIES=	www misc
MASTER_SITES=	SF/${PORTNAME}/stable/2.5

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open Source Human Resource Management

.include <bsd.port.pre.mk>

USE_PHP=	mysql
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
HRMDIR=		www/orangehrm

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s#${WRKSRC}#${HRMDIR}#g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s#${WRKSRC}#@dirrm ${HRMDIR}#g" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/${HRMDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${HRMDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${HRMDIR}' \
		>> ${TMPPLIST}
	${CHMOD} -R 755 ${PREFIX}/${HRMDIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${PREFIX}/${HRMDIR}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
