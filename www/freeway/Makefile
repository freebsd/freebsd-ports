# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	freeway
PORTVERSION=	1.4.2.197
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}-ecom/Freeway/${PORTVERSION}%20Sathish
DISTNAME=	${PORTNAME}_${PORTVERSION:S,.,_,g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced Open Source eCommerce Platform

USE_PHP=	mysql
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}' \
		 > ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}' \
		>> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
