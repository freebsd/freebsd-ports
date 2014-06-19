# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	orangehrm
PORTVERSION=	3.1.2
CATEGORIES=	www misc
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open Source Human Resource Management

USES=		zip
USE_PHP=	mysql
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
HRMDIR=		www/orangehrm

pre-install:
	@${FIND} -s -d ${WRKSRC} -type l | ${SED} "s#${WRKSRC}#${HRMDIR}#g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s#${WRKSRC}#${HRMDIR}#g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s#${WRKSRC}#@dirrm ${HRMDIR}#g" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${HRMDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${HRMDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${HRMDIR}' \
		>> ${TMPPLIST}
	${CHMOD} -R 755 ${STAGEDIR}${PREFIX}/${HRMDIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${STAGEDIR}${PREFIX}/${HRMDIR}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
