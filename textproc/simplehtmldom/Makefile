# New ports collection makefile for: simplehtmldom
# Date created:		2010-01-18
# Whom:			Joe Horn <joehorn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		simplehtmldom
DISTVERSION=		1.11
PORTREVISION=		1
CATEGORIES=		textproc www
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}
DISTNAME=		${PORTNAME}_${DISTVERSION:S/./_/g}

MAINTAINER=		joehorn@gmail.com
COMMENT=		PHP Simple HTML DOM Parser

WRKSRC=			${WRKDIR}/${PORTNAME}

USE_ZIP=		YES
NO_BUILD=		YES

USE_PHP=		pcre

DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	4

SUB_FILES+=		pkg-message
SUB_LIST+=		DATADIR=${DATADIR} PREFIX=${PREFIX}

EXAMPLES_SUB_DIR=	scraping
DOCS_SUB_DIR=		css img js

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DATADIR}
	@${ECHO_CMD} "=> Installing simple_html_dom.php to ${DATADIR}"
	@${INSTALL} -c -m 644 ${WRKSRC}/simple_html_dom.php ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for _DOC in ${DOCS_SUB_DIR}
	@${MKDIR} ${DOCSDIR}/${_DOC}
.endfor
	@${ECHO_CMD} "=> Installing manuals to ${DOCSDIR}"
	@cd ${WRKSRC}/manual && ${FIND} * -type f -exec ${INSTALL} -c -m 644 "{}" "${DOCSDIR}/{}" \;
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for _EXAMPLE in ${EXAMPLES_SUB_DIR}
	@${MKDIR} ${EXAMPLESDIR}/${_EXAMPLE}
.endfor
	@${ECHO_CMD} "=> Installing examples to ${EXAMPLESDIR}"
	@cd ${WRKSRC}/example && ${FIND} * -type f -exec ${INSTALL} -c -m 644 "{}" "${EXAMPLESDIR}/{}" \;
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
