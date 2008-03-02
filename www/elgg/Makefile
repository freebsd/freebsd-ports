# New ports collection makefile for:   elgg
# Date created:		25 Feberury 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	elgg
PORTVERSION=	0.9.1
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	wenheping@gmail.com
COMMENT=	Blogging and social networking platform

USE_PHP=	gd gettext
USE_GETTEXT=	yes
WRKSRC=		${WRKDIR}/elgg-0.9.1

OPTIONS=	MYSQL   "Add support for a MySQL database server" ON \
		PGSQL   "Add support for a PostgreSQL database server" Off \
		LDAP    "Add LDAP authentication functionality" Off

NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} -f config.php

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@if [ ! -f ${WWWDIR}/config.php ]; then \
	${CP} -p ${WWWDIR}/config-dist.php ${WWWDIR}/config.php ; fi
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CHMOD} 777 ${WWWDIR}/data
	@${ECHO_CMD} '@exec ${CHMOD} 777 ${WWWDIR}/data' \
		>> ${TMPPLIST}
	@${CHMOD} 666 ${WWWDIR}/config.php
	@${ECHO_CMD} '@exec ${CHMOD} 666 ${WWWDIR}/config.php' \
		>> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
