# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	pmwiki
PORTVERSION=	2.2.64
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.pmwiki.org/pub/pmwiki/
EXTRACT_SUFX=	.tgz

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	WikiWikiWeb clone using PHP

USE_PHP=	mbstring session
WANT_PHP_WEB=	yes

NO_BUILD=	yes

PORTDOCS=	*

PLIST_SUB+=	PMWIKIDIR=${PMWIKIDIR}
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
	@${MKDIR} -m 755 ${STAGEDIR}${PREFIX}/${PMWIKIDIR}
	@cd ${WRKSRC} && ${FIND} . ! \( -name docs -prune \) | \
		${CPIO} ${CPIOFLAGS} ${STAGEDIR}${PREFIX}/${PMWIKIDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${PMWIKIDIR}
	@${INSTALL} -o ${DOCOWN} -g ${DOCGRP} -m 555 -d ${STAGEDIR}${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

post-install:
	@${MKDIR} -m 775 ${STAGEDIR}${PREFIX}/${PMWIKIDIR}/wiki.d
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${PMWIKIDIR}/wiki.d

.include <bsd.port.mk>
