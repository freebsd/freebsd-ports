PORTNAME=	pmwiki
DISTVERSION=	2.5.8
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.pmwiki.org/pub/pmwiki/

MAINTAINER=	m.ne@gmx.net
COMMENT=	WikiWikiWeb clone using PHP
WWW=		https://www.pmwiki.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

USES=		cpe tar:tgz php:web
USE_PHP=	mbstring session

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PMWIKIDIR=${PMWIKIDIR}
PLIST_SUB=	PMWIKIDIR=${PMWIKIDIR} WWWGRP=${WWWGRP} WWWOWN=${WWWOWN}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PMWIKIDIR}/wiki.d
	@cd ${WRKSRC} && ${FIND} . ! \( -name docs -prune \) | \
		${CPIO} ${CPIOFLAGS} ${STAGEDIR}${PREFIX}/${PMWIKIDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
