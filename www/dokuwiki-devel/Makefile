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

DIST_VER=	${PORTNAME}-rc2006-10-19
USE_PHP=	gd mbstring pcre session xml zlib
NO_BUILD=	YES
WANT_PHP_WEB=	YES

DOKUWIKI_DIR?=	www/${PORTNAME}
WRKSRC=		${WRKDIR}/${DIST_VER}
PLIST_SUB=	DOKUWIKI_DIR=${DOKUWIKI_DIR}
TEMP_PLIST=		${WRKDIR}/temp-pkg-plist

.include <bsd.port.pre.mk>

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
