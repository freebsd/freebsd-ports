# New ports collection makefile for:	eyeOS
# Date created:		2006-04-04
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	eyeOS
DISTVERSION=	0.9.3-5
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/0.9.3-5

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Web Based Desktop System

NO_BUILD=	yes
USE_PHP=	pcre session

WRKSRC=		${WRKDIR}/${PORTNAME}
EYEDIR?=	${PREFIX}/www/${PORTNAME}
RWDIRS=		etc
RODIRS=		apps login system
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	EYEDIR="${EYEDIR:S,^${PREFIX}/,,}"
SUB_LIST+=	EYEDIR=${EYEDIR}

post-extract:
	@${RM} -f ${WRKSRC}/DOCS/gpl-license.txt
	@${MV} ${WRKSRC}/README.txt ${WRKSRC}/DOCS/USER.MANUAL

post-patch:
	@${FIND} ${WRKSRC}/ -iname \*php | ${XARGS} ${REINPLACE_CMD} -e 's/0777/0775/g'
	@${FIND} ${WRKSRC}/ -iname \*bak -delete

do-install:
	@${INSTALL} -d ${EYEDIR}
	@${CP} -Rp ${WRKSRC}/[a-z]* ${EYEDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${EYEDIR}/
	@${CHMOD} 775 ${RWDIRS:S,^,${EYEDIR}/,}
	${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${EYEDIR:S,^${PREFIX}/,,}/ >> ${TMPPLIST}
	${ECHO_CMD} @exec ${CHMOD} 775 ${RWDIRS:S,^,%D/${EYEDIR:S,^${PREFIX}/,,}/,} >> ${TMPPLIST}
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}
	@${CP} -Rp ${WRKSRC}/DOCS/ ${DOCSDIR}/
	@${CHMOD} -R ${SHAREMODE} ${DOCSDIR}/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

# Maintainer section
create-plist: build
	${FIND} -s ${WRKSRC} -type f -or -type l | \
		${SED} -e 's#^${WRKSRC}/DOCS#%%PORTDOCS%%%%DOCSDIR%%#' \
			-e 's#^${WRKSRC}#%%EYEDIR%%#' > ${PLIST}
	${FIND} -ds ${WRKSRC}/DOCS ${RODIRS:S,^,${WRKSRC}/,} -type d | \
		${SED} -e 's#^${WRKSRC}/DOCS#%%PORTDOCS%%@dirrm %%DOCSDIR%%#' \
			-e 's#^${WRKSRC}/system/themes$$#@dirrmtry %%EYEDIR%%/system/themes#' \
			-e 's#^${WRKSRC}/system$$#@dirrmtry %%EYEDIR%%/system#' \
			-e 's#^${WRKSRC}#@dirrm %%EYEDIR%%#' >> ${PLIST}
	${FIND} -ds ${RWDIRS:S,^,${WRKSRC}/,} -type d | \
		${SED} -e 's#^${WRKSRC}#@dirrmtry %%EYEDIR%%#' >> ${PLIST}
	${ECHO_CMD} @dirrmtry %%EYEDIR%% >> ${PLIST}

.include <bsd.port.mk>
