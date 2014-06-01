# Created by: chinsan
# $FreeBSD$

PORTNAME=	phpsecinfo
PORTVERSION=	0.2.1
CATEGORIES=	security www
MASTER_SITES=	LOCAL/chinsan

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP environment security auditing tool

LICENSE=	BSD3CLAUSE

USES=		zip
USE_PHP=	pcre
WANT_PHP_WEB=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-20070406
TEMP_PLIST=	${WRKDIR}/temp-pkg-plist

PLIST_SUB=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	@make makesum extract
	@${ECHO_CMD} "@owner %%WWWOWN%%" > ${TEMP_PLIST}
	@${ECHO_CMD} "@group %%WWWGRP%%" >> ${TEMP_PLIST}
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|%%WWWDIR%%/|' >> ${TEMP_PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm %%WWWDIR%%/|' >> ${TEMP_PLIST} \
		&& ${ECHO_CMD} "@dirrmtry %%WWWDIR%%" >> ${TEMP_PLIST}

.include <bsd.port.mk>
