# New ports collection makefile for:	dokuwiki-devel
# Date created:		2006-06-09
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dokuwiki
PORTVERSION=	${DIST_VER:S/${PORTNAME}//:S/-//g:S/rc//g}
CATEGORIES=	www
MASTER_SITES=	http://chinsan2.twbbs.org/distfiles/ \
		ftp://chinsan2.twbbs.org/distfiles/ \
		http://www.splitbrain.org/_media/projects/dokuwiki/
PKGNAMESUFFIX=	-devel
DISTNAME=	${DIST_VER}
EXTRACT_SUFX=	.tgz

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A simple and easy to use wiki, no database required

DIST_VER=	${PORTNAME}-rc2006-10-08
USE_PHP=	gd mbstring pcre session xml zlib
NO_BUILD=	YES
WANT_PHP_WEB=	YES

DOKUWIKI_DIR?=	www/${PORTNAME}
WRKSRC=		${WRKDIR}/${DIST_VER}
PLIST_SUB=	DOKUWIKI_DIR=${DOKUWIKI_DIR}
TEMP_PLIST=		${WRKDIR}/temp-pkg-plist

.if defined(BATCH)
WIKI_LANG?=	en
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WIKI_LANG)
	@${ECHO_MSG} '*******************************************************'
	@${ECHO_MSG} '* You can customize the wiki language by typing	      *'
	@${ECHO_MSG} '*                               Use make-flag:        *'
	@${ECHO_MSG} '*  - Arabic			WIKI_LANG=ar	      *'
	@${ECHO_MSG} '*  - Basque			WIKI_LANG=eu	      *'
	@${ECHO_MSG} '*  - Brazilian Portuguese       WIKI_LANG=pt-br	      *'
	@${ECHO_MSG} '*  - Catalan			WIKI_LANG=ca	      *'
	@${ECHO_MSG} '*  - Chinese(Simplified)        WIKI_LANG=zh	      *'
	@${ECHO_MSG} '*  - Chinese(Traditional)       WIKI_LANG=zh-tw	      *'
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
	@${ECHO_MSG} '*  - Indonesian			WIKI_LANG=id	      *'
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
	@${ECHO_MSG} '*  - Serbian			WIKI_LANG=sr	      *'
	@${ECHO_MSG} '*  - Slovak			WIKI_LANG=sk	      *'
	@${ECHO_MSG} '*  - Slovenian			WIKI_LANG=sl	      *'
	@${ECHO_MSG} '*  - Spanish			WIKI_LANG=es	      *'
	@${ECHO_MSG} '*  - Swedish			WIKI_LANG=sv	      *'
	@${ECHO_MSG} '*  - Turkish			WIKI_LANG=tr	      *'
	@${ECHO_MSG} '*  - Vietnamese			WIKI_LANG=vi	      *'
	@${ECHO_MSG} '*					              *'
	@${ECHO_MSG} '* Example: "make WIKI_LANG=zh-tw install clean"	      *'
	@${ECHO_MSG} '*******************************************************'
.endif

pre-patch:
.if defined(WIKI_LANG)
	@${REINPLACE_CMD} -e 's|lang\(.*\)'en'|lang\1'${WIKI_LANG}'|g' \
		${WRKSRC}/conf/dokuwiki.php
	@${FIND} ${WRKSRC}/conf -name "*.php.bak" -delete
.endif

x-generate-plist:
	@make makesum
	@make patch
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|%%DOKUWIKI_DIR%%/|' > ${TEMP_PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm %%DOKUWIKI_DIR%%/|' >> ${TEMP_PLIST} \
		&& ${ECHO_CMD} "@dirrmtry %%DOKUWIKI_DIR%%" >> ${TEMP_PLIST}

do-install:
# Data files
	-${MKDIR} ${PREFIX}/${DOKUWIKI_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${DOKUWIKI_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKI_DIR}

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|; s|%%PORTNAME%%|${PORTNAME}|' \
		-e 's|%%DOKUWIKI_DIR%%|${DOKUWIKI_DIR}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
