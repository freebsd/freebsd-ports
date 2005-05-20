# New ports collection makefile for:	dokuwiki
# Date created:		2005-04-10
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	dokuwiki
PORTVERSION=	20050507
CATEGORIES=	www
MASTER_SITES=	http://www.splitbrain.org/Programming/PHP/DokuWiki/
DISTNAME=	${PORTNAME}-2005-05-07
EXTRACT_SUFX=	.tgz

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	A simple and easy to use wiki, no database required

USE_PHP=	pcre session xml zlib
PHP4_PORT?=	www/mod_php4
NO_BUILD=	YES
WANT_PHP_WEB=	YES
USE_REINPLACE=yes

pre-fetch:
.if !defined(DOKUWIKIDIR)
	 @${ECHO_MSG} ""
	 @${ECHO_MSG} "Define DOKUWIKIDIR to override default of '${DOKUWIKIDIR}'."
	 @${ECHO_MSG} ""
.endif

WWWDOCROOT?=	www/data-dist
DOKUWIKIURL?=	${PORTNAME}
WWWOWN?=	www
WWWGRP?=	www
DOKUWIKIDIR?=	${WWWDOCROOT}/${DOKUWIKIURL}
PLIST=		${WRKDIR}/pkg-plist

.if defined(BATCH)
WIKI_LANG?=en
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WIKI_LANG)
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* You can customize the wiki language by typing	      *'
	@${ECHO_MSG} '*                                 Use make-flag:      *'
	@${ECHO_MSG} '*  - Basque			WIKI_LANG=eu	      *'
	@${ECHO_MSG} '*  - Brazilian Portuguese       WIKI_LANG=pt-br	      *'
	@${ECHO_MSG} '*  - Simplified Chinese		WIKI_LANG=zh	      *'
	@${ECHO_MSG} '*  - Traditional Chinese        WIKI_LANG=zh-tw	      *'
	@${ECHO_MSG} '*  - Czech			WIKI_LANG=cs	      *'
	@${ECHO_MSG} '*  - Danish			WIKI_LANG=da          *'
	@${ECHO_MSG} '*  - Dutch			WIKI_LANG=nl	      *'
	@${ECHO_MSG} '*  - English			WIKI_LANG=en	      *'
	@${ECHO_MSG} '*  - Esperanto			WIKI_LANG=eo	      *'
#	@${ECHO_MSG} '*  - Estonian			WIKI_LANG=et	      *'
	@${ECHO_MSG} '*  - Finnish			WIKI_LANG=fi          *'
	@${ECHO_MSG} '*  - French			WIKI_LANG=fr	      *'
	@${ECHO_MSG} '*  - German			WIKI_LANG=de	      *'
	@${ECHO_MSG} '*  - Hebrew			WIKI_LANG=he	      *'
	@${ECHO_MSG} '*  - Hungarian			WIKI_LANG=hu	      *'
	@${ECHO_MSG} '*  - Italian			WIKI_LANG=it	      *'
	@${ECHO_MSG} '*  - Korean			WIKI_LANG=ko	      *'
	@${ECHO_MSG} '*  - Norwegian			WIKI_LANG=no	      *'
	@${ECHO_MSG} '*  - Polish			WIKI_LANG=pl	      *'
	@${ECHO_MSG} '*  - Portuguese			WIKI_LANG=pt	      *'
	@${ECHO_MSG} '*  - Romanian			WIKI_LANG=ro	      *'
	@${ECHO_MSG} '*  - Russian			WIKI_LANG=ru	      *'
	@${ECHO_MSG} '*  - Spanish			WIKI_LANG=es	      *'
	@${ECHO_MSG} '*  - Swedish			WIKI_LANG=sv	      *'
	@${ECHO_MSG} '*  - Vietnamese			WIKI_LANG=vi	      *'
	@${ECHO_MSG} '*					              *'
	@${ECHO_MSG} '* Example: "make WIKI_LANG=zh-tw install clean"	      *'
	@${ECHO_MSG} '*******************************************************'
.endif

pre-patch:
.if defined(WIKI_LANG)
	@${REINPLACE_CMD} -e 's|'en'|'${WIKI_LANG}'|g' ${WRKSRC}/conf/dokuwiki.php
	${FIND} ${WRKSRC}/conf -name "*.php.bak" -delete
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sfs|bbs|g' ${WRKSRC}/lang/zh-tw/edit.txt
	${FIND} ${WRKSRC}/lang/zh-tw -name "*.txt.bak" -delete

pre-install:
	cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${DOKUWIKIDIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${DOKUWIKIDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} ${DOKUWIKIDIR}/changes.log >> ${PLIST} \
		&& ${ECHO_CMD} "@unexec rmdir %D/${DOKUWIKIDIR} 2>/dev/null || true">> ${PLIST}

do-install:
	# Data files
	-${MKDIR} ${PREFIX}/${DOKUWIKIDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKIDIR}
	@${CHMOD} 755 ${PREFIX}/${DOKUWIKIDIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${DOKUWIKIDIR}
	# Setup the correct permissions
	@${TOUCH} ${PREFIX}/${DOKUWIKIDIR}/changes.log
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKIDIR}/changes.log
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKIDIR}/data
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKIDIR}/media
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKIDIR}/attic

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%WWWDOCROOT%%|${WWWDOCROOT}|' \
		-e 's|%%DOKUWIKIURL%%|${DOKUWIKIURL}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
