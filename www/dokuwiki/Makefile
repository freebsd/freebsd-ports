# New ports collection makefile for:	dokuwiki
# Date created:		2005-04-10
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	dokuwiki
PORTVERSION=	${DIST_VER:S/${PORTNAME}//:S/-//g}
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.splitbrain.org/_media/projects/dokuwiki/ \
		LOCAL/chinsan/${PORTNAME}
DISTNAME=	${DIST_VER}
EXTRACT_SUFX=	.tgz

MAINTAINER=	chris@officialunix.com
COMMENT=	A simple and easy to use wiki, no database required

DIST_VER=	${PORTNAME}-2009-02-14
USE_PHP=	gd mbstring pcre session xml zlib
NO_BUILD=	YES
WANT_PHP_WEB=	YES

DOKUWIKI_DIR?=	www/${PORTNAME}
WRKSRC=		${WRKDIR}/${DIST_VER}
PLIST_SUB=	DOKUWIKI_DIR=${DOKUWIKI_DIR}
TEMP_PLIST=	${WRKDIR}/temp-pkg-plist

REINPLACE_ARGS=	-i ''

.include <bsd.port.pre.mk>

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|%%DOKUWIKI_DIR%%/|' > ${TEMP_PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm %%DOKUWIKI_DIR%%/|' >> ${TEMP_PLIST} \
		&& ${ECHO_CMD} "@dirrmtry %%DOKUWIKI_DIR%%" >> ${TEMP_PLIST}

post-patch:
	@${REINPLACE_CMD} -e 's|9|10|' ${WRKSRC}/conf/msg
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/bin/*.php
	@${FIND} ${WRKSRC}/bin -name '*.orig' -delete

do-install:
# Data files
	-${MKDIR} ${PREFIX}/${DOKUWIKI_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${DOKUWIKI_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKI_DIR}

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|; s|%%PORTNAME%%|${PORTNAME}|' \
		-e 's|%%DOKUWIKI_DIR%%|${DOKUWIKI_DIR}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
