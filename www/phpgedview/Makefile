# New ports collection makefile for:	phpGedView
# Date created:				20 février 2004
# Whom:					Hubert Tournier <hubert@frbsd.org>
#
# $FreeBSD$
#

PORTNAME=	phpGedView
PORTVERSION=	4.2.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:L}/1%20PhpGedView/PhpGedView%20v${PORTVERSION}
DISTNAME=	${PORTNAME:S/p/P/}-basic-${PORTVERSION}

MAINTAINER=	fbsd@opal.com
COMMENT=	Online genealogy viewer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
FETCH_ARGS=	-pRr

USE_ZIP=	yes
USE_PHP=	calendar dom gd pcre session xml
NO_BUILD=	yes

SUB_FILES=	pkg-message pkg-deinstall
DISTATE=	config.php config_download.php config_gedcom.php

OPTIONS=\
	MYSQL	"Install MYSQL data storage option"		off \
	PGSQL	"Install Postgress data storage option"		off \
	SQLITE	"Install SQLITE data storage option"		on

.include <bsd.port.pre.mk>

.if !defined(WITH_MYSQL) && !defined(WITH_PGSQL) && !defined(WITH_SQLITE)
check-makevars::
		@${ECHO_CMD} "${PKGNAME}: Makefile options: at least one database: MYSQL, PGSQL or SQLITE must be installed."
		@${FALSE}
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
.endif

.if defined(WITH_SQLITE)
USE_PHP +=	sqlite
.endif

post-extract:
.for f in ${DISTATE}
	@${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}-dist
.endfor

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/index ${WWWDIR}/media
	@${CHMOD} -R u+w ${WWWDIR}/index ${WWWDIR}/media
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/index ${WWWDIR}/media' >>${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R u+w ${WWWDIR}/index ${WWWDIR}/media' >>${TMPPLIST}

post-install:
.for f in ${DISTATE}
	@if [ ! -f ${WWWDIR}/${f} ]; then \
		${CP} -p ${WWWDIR}/${f}-dist ${WWWDIR}/${f}; \
		${CHMOD} a+w ${WWWDIR}/${f}; \
	fi
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
