# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	pmwiki
PORTVERSION=	2.2.92
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.pmwiki.org/pub/pmwiki/

MAINTAINER=	tz@FreeBSD.org
COMMENT=	WikiWikiWeb clone using PHP

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

USES=		cpe tar:tgz php:web
USE_PHP=	mbstring session

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*

PLIST_SUB=	PMWIKIDIR=${PMWIKIDIR} WWWGRP=${WWWGRP} WWWOWN=${WWWOWN}
SUB_LIST+=	PMWIKIDIR=${PMWIKIDIR}
SUB_FILES=	pkg-message

pre-fetch:
.if !defined(PMWIKIDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define PMWIKIDIR (now: ${PMWIKIDIR})"
	@${ECHO_MSG} "to override default: www/pmwiki".
	@${ECHO_MSG} ""
.endif

PMWIKIDIR?=	www/pmwiki

CPIOFLAGS=	--quiet -pdm -R ${WWWOWN}:${WWWGRP}

post-extract:
	@${MV} ${WRKSRC}/README.txt ${WRKSRC}/docs
	@${MV} ${WRKSRC}/docs/sample-config.php ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PMWIKIDIR}
	@cd ${WRKSRC} && ${FIND} . ! \( -name docs -prune \) | \
		${CPIO} ${CPIOFLAGS} ${STAGEDIR}${PREFIX}/${PMWIKIDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PMWIKIDIR}/wiki.d

.include <bsd.port.mk>
