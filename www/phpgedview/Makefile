# New ports collection makefile for:	phpGedView
# Date created:				20 février 2004
# Whom:					Hubert Tournier <hubert@frbsd.org>
#
# $FreeBSD$
#

PORTNAME=	phpGedView
PORTVERSION=	4.1.4
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	phpgedview
DISTNAME=	${PORTNAME:S/p/P/}-basic-${PORTVERSION}

MAINTAINER=	fbsd@opal.com
COMMENT=	Online genealogy viewer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USE_ZIP=	yes
USE_PHP=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message pkg-deinstall
DISTATE=	config.php config_download.php config_gedcom.php

post-extract:
.for f in ${DISTATE}
	@${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}-dist
.endfor

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} 755 ${WWWDIR}
	@${CHMOD} 644 ${WWWDIR}/index
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >>${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${WWWDIR}' >>${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 644 ${WWWDIR}/index' >>${TMPPLIST}

post-install:
.for f in ${DISTATE}
	@if [ ! -f ${WWWDIR}/${f} ]; then \
		${CP} -p ${WWWDIR}/${f}-dist ${WWWDIR}/${f}; \
		${CHMOD} 666 ${WWWDIR}/${f}; \
	fi
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
