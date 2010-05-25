# Ports collection makefile for:	PmWiki
# Date created:		Sat Feb 26 06:16:50 CST 2005
# Whom:				Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pmwiki
PORTVERSION=	2.2.16
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://pmwiki.org/pub/pmwiki/
EXTRACT_SUFX=	.tgz

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A WikiWikiWeb clone using PHP

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
	@${MKDIR} -m 755 ${PREFIX}/${PMWIKIDIR}
	@cd ${WRKSRC} && ${FIND} . ! \( -name docs -prune \) | \
		${CPIO} ${CPIOFLAGS} ${PREFIX}/${PMWIKIDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${PMWIKIDIR}
.if !defined(NOPORTDOCS)
	@${INSTALL} -o ${DOCOWN} -g ${DOCGRP} -m 555 -d ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

post-install:
	@${MKDIR} -m 775 ${PREFIX}/${PMWIKIDIR}/wiki.d
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${PMWIKIDIR}/wiki.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
