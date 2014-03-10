# Created by: chinsan
# $FreeBSD$

PORTNAME=	phpsecinfo
PORTVERSION=	0.2.1
CATEGORIES=	security www
MASTER_SITES=	LOCAL/chinsan

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP environment security auditing tool

USES=		zip
USE_PHP=	pcre
WANT_PHP_WEB=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-20070406
TEMP_PLIST=	${WRKDIR}/temp-pkg-plist

NO_STAGE=	yes
do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -R ${WRKSRC}/ ${WWWDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGROUP} ${WWWDIR}

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	@make makesum extract
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|%%WWWDIR%%/|' > ${TEMP_PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm %%WWWDIR%%/|' >> ${TEMP_PLIST} \
		&& ${ECHO_CMD} "@dirrmtry %%WWWDIR%%" >> ${TEMP_PLIST}

.include <bsd.port.mk>
