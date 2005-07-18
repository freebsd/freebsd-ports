# New ports collection makefile for:	dokuwiki
# Date created:		2005-04-10
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	dokuwiki
PORTVERSION=	20050713
CATEGORIES=	www
MASTER_SITES=	http://www.splitbrain.org/Programming/PHP/DokuWiki/
DISTNAME=	${PORTNAME}-2005-07-13
EXTRACT_SUFX=	.tgz

# Maintainership available: drop me a line if interested :p
MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	A simple and easy to use wiki, no database required

USE_PHP=	gd pcre session xml zlib
PHP4_PORT?=	www/mod_php4
NO_BUILD=	YES
WANT_PHP_WEB=	YES
USE_REINPLACE=	YES

pre-fetch:
.if !defined(DOKUWIKI_DIR)
	 @${ECHO_MSG} ""
	 @${ECHO_MSG} "Define DOKUWIKI_DIR to override default of '${DOKUWIKI_DIR}'."
	 @${ECHO_MSG} ""
.endif

WWWDOCROOT?=	www/data
DOKUWIKI_URL?=	${PORTNAME}
WWWOWN?=	www
WWWGRP?=	www
DOKUWIKI_DIR?=	${WWWDOCROOT}/${DOKUWIKI_URL}
PLIST=		${WRKDIR}/pkg-plist

.if defined(BATCH)
WIKI_LANG?=en
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WIKI_LANG)
	@${ECHO_MSG} '*******************************************************'
	@${ECHO_MSG} '* You can customize the wiki language by typing	      *'
	@${ECHO_MSG} '*                               Use make-flag:        *'
	@${ECHO_MSG} '*  - Basque			WIKI_LANG=eu	      *'
	@${ECHO_MSG} '*  - Brazilian Portuguese       WIKI_LANG=pt-br	      *'
	@${ECHO_MSG} '*  - Simplified Chinese		WIKI_LANG=zh	      *'
	@${ECHO_MSG} '*  - Traditional Chinese        WIKI_LANG=zh-tw	      *'
	@${ECHO_MSG} '*  - Czech			WIKI_LANG=cs	      *'
	@${ECHO_MSG} '*  - Danish			WIKI_LANG=da          *'
	@${ECHO_MSG} '*  - Dutch			WIKI_LANG=nl	      *'
	@${ECHO_MSG} '*  - English			WIKI_LANG=en	      *'
	@${ECHO_MSG} '*  - Esperanto			WIKI_LANG=eo	      *'
	@${ECHO_MSG} '*  - Estonian			WIKI_LANG=et	      *'
	@${ECHO_MSG} '*  - Finnish			WIKI_LANG=fi          *'
	@${ECHO_MSG} '*  - French			WIKI_LANG=fr	      *'
	@${ECHO_MSG} '*  - German			WIKI_LANG=de	      *'
	@${ECHO_MSG} '*  - Hebrew			WIKI_LANG=he	      *'
	@${ECHO_MSG} '*  - Hungarian			WIKI_LANG=hu	      *'
	@${ECHO_MSG} '*  - Italian			WIKI_LANG=it	      *'
	@${ECHO_MSG} '*  - Japanese			WIKI_LANG=ja	      *'
	@${ECHO_MSG} '*  - Korean			WIKI_LANG=ko	      *'
	@${ECHO_MSG} '*  - Latvian			WIKI_LANG=lv	      *'
	@${ECHO_MSG} '*  - Lithuanian			WIKI_LANG=lt	      *'
	@${ECHO_MSG} '*  - Norwegian			WIKI_LANG=no	      *'
	@${ECHO_MSG} '*  - Polish			WIKI_LANG=pl	      *'
	@${ECHO_MSG} '*  - Portuguese			WIKI_LANG=pt	      *'
	@${ECHO_MSG} '*  - Romanian			WIKI_LANG=ro	      *'
	@${ECHO_MSG} '*  - Russian			WIKI_LANG=ru	      *'
	@${ECHO_MSG} '*  - Spanish			WIKI_LANG=es	      *'
	@${ECHO_MSG} '*  - Slovenian			WIKI_LANG=sl	      *'
	@${ECHO_MSG} '*  - Swedish			WIKI_LANG=sv	      *'
	@${ECHO_MSG} '*  - Vietnamese			WIKI_LANG=vi	      *'
	@${ECHO_MSG} '*					              *'
	@${ECHO_MSG} '* Example: "make WIKI_LANG=zh-tw install clean"	      *'
	@${ECHO_MSG} '*******************************************************'
.endif

pre-patch:
.if defined(WIKI_LANG)
	@${REINPLACE_CMD} -e 's|lang\(.*\)'en'|lang\1'${WIKI_LANG}'|g' \
		${WRKSRC}/conf/dokuwiki.php
	${FIND} ${WRKSRC}/conf -name "*.php.bak" -delete
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sfs|bbs|g' ${WRKSRC}/inc/lang/zh-tw/edit.txt
	${FIND} ${WRKSRC}/inc/lang/zh-tw -name "*.txt.bak" -delete

pre-install:
	${TOUCH} ${WRKSRC}/data/changes.log
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${DOKUWIKI_DIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${DOKUWIKI_DIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} "@unexec ${RMDIR} %D/${DOKUWIKI_DIR} 2>/dev/null || true">> ${PLIST}

do-install:
	# Data files
	-${MKDIR} ${PREFIX}/${DOKUWIKI_DIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKI_DIR}
	@${CHMOD} 755 ${PREFIX}/${DOKUWIKI_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${DOKUWIKI_DIR}
	# Setup the correct permissions
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKI_DIR}/data

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%DOKUWIKI_DIR%%|${DOKUWIKI_DIR}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
