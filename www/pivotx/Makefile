# New ports collection makefile for:	pivotx
# Date created:		2011-01-05
# Whom:			Fumiyuki Shimizu <fumifumi@abacustech.jp>
#
# $FreeBSD$
#

PORTNAME=	pivotx
PORTVERSION=	2.3.0
CATEGORIES=	www
MASTER_SITES=	SF/pivot-weblog/PivotX \
		http://pivotx.net/files/ \
		http://pivotx.net/files/archived/
DISTNAME=	pivotx_2.3.0
EXTRACT_SUFX=	.tgz

MAINTAINER=	fumifumi@abacustech.jp
COMMENT=	Software to help you maintain dynamic sites such as weblogs

LICENSE=	GPLv2
LICENSE_FILE=	${DOCS_WRKSRC}/LICENSE.txt

DOCS=		LICENSE.txt README.txt example.htaccess
DOCS_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}-${PORTREVISION}-docs

# Requirements:
# http://book.pivotx.net/index.php?page=app-e#anchor-determining-if-your-server-meets-pivotxs-requirements

OPTIONS=	MYSQL	"Use MySQL instead of flat files" off

.include <bsd.port.options.mk>

WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=4
USE_PHP=	session gettext xml gd pcre tokenizer
USE_GETTEXT=	yes

.if exists(${PHPBASE}/lib/php/${PHP_EXT_DIR}/simplexml.so) || !exists(${PHPBASE}/lib/php/${PHP_EXT_DIR}/dom.so)
USE_PHP+=	simplexml
.else
USE_PHP+=	dom
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
USE_PHP+=	mysql
.endif

NO_BUILD=	YES

TEMP_WRKSRC=	${WRKDIR}/.temp-${PORTNAME}-${PORTVERSION}-${PORTREVISION}
TEMP_DIFF=	${WRKDIR}/.temp-diff-${PORTNAME}-${PORTVERSION}-${PORTREVISION}

BLOGURL=	${PORTNAME}
.if defined(BLOGDIR)
# Relative to ${PREFIX}
WWWDIR=		${PREFIX}/${BLOGDIR}
.endif

SUB_FILES=	pkg-message
SUB_LIST=	BLOGURL=${BLOGURL}

# http://book.pivotx.net/page/1-2#anchor-setting-the-file-rights
WRITABLEDIRS=		images pivotx/templates pivotx/db
USEREDITABLEDIRS=	pivotx/templates

post-extract:
	@if ${TEST} -e '${TEMP_WRKSRC}'; then ${RM} -r '${TEMP_WRKSRC}'; fi
	@${MKDIR} '${TEMP_WRKSRC}'
	@${MV} '${WRKDIR}/'* '${TEMP_WRKSRC}'
	@${MV} '${TEMP_WRKSRC}' '${WRKSRC}'
	@${MKDIR} '${DOCS_WRKSRC}'
.for FILES in ${DOCS}
	@${MV} '${WRKSRC}/${FILES}' '${DOCS_WRKSRC}'
.endfor

post-patch:
	@cd '${WRKSRC}' && { ${FIND} . -type f -name '*.orig' -print0 | ${XARGS} -0 -J % ${MV} % '${DOCS_WRKSRC}'; }

do-install:
	@if ${TEST} -e '${TEMP_DIFF}'; then ${RM} -f '${TEMP_DIFF}'; fi
	@${TOUCH} '${TEMP_DIFF}'
.for DIR in ${USEREDITABLEDIRS}
	@if ${TEST} -d '${WWWDIR}/${DIR}'; then	\
	   cd '${WRKSRC}/${DIR}' && { ${DIFF} -auwr . '${WWWDIR}/${DIR}' | ${EGREP} -v -e '^Only[[:space:]]+in[[:space:]]' >>'${TEMP_DIFF}' || ${TRUE}; }	\
	 fi
.endfor
	@if ${TEST} -s '${TEMP_DIFF}'; then	\
	   ${ECHO} '*******************************************************';	\
	   ${ECHO} 'CAUTION CAUTION CAUTION CAUTION CAUTION CAUTION CAUTION';	\
	   ${ECHO} '*******************************************************';	\
	   ${ECHO} 'Output of diff: ${TEMP_DIFF}';	\
	   ${ECHO};	\
	   ${ECHO} 'Installer will *OVERWRITE* files on ${WWWDIR}';	\
	   ${ECHO} 'Press ctrl-C *now* to backup them manually.';	\
	   sleep 7;	\
	 fi
.if !defined(NOPORTDOCS)
	@${MKDIR} '${DOCSDIR}'
	@cd '${DOCS_WRKSRC}' && ${COPYTREE_SHARE} . '${DOCSDIR}'
.endif
	@${MKDIR} '${WWWDIR}'
	@cd '${WRKSRC}' && ${COPYTREE_SHARE} . '${WWWDIR}'
.for DIR in ${WRITABLEDIRS}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} '${WWWDIR}/${DIR}'
	@${FIND} '${WWWDIR}/${DIR}' -type d -print0 | ${XARGS} -0 ${CHMOD} u=rwx,go=rx
	@${FIND} '${WWWDIR}/${DIR}' -type f -print0 | ${XARGS} -0 ${CHMOD} u=rw,go=r
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
