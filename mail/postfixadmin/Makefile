# New ports collection makefile for:    postfixadmin
# Date created:                         23 October 2003
# Whom:                                 Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	postfixadmin
PORTVERSION=	2.2.1.1
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	terry@sucked-in.com
COMMENT=	PHP web-based management tool for Postfix virtual domains and users

NO_BUILD=	yes

SUB_FILES+=	pkg-message

OPTIONS=	MYSQL "MySQL back-end (use mysql PHP extension)" on
OPTIONS+=	MYSQLI "MySQL 4.1+ back-end (use mysqli PHP extension)" off
OPTIONS+=	PGSQL "PostgreSQL back-end (use pgsql PHP extension)" off

.include <bsd.port.pre.mk>

USE_PHP=	pcre session

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_MYSQLI)
USE_PHP+=	mysqli
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITHOUT_MYSQL) && !defined(WITH_MYSQLI) && !defined(WITH_PGSQL)
IGNORE=	needs at least one database back-end
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${PREFIX}/www/postfixadmin/VIRTUAL_VACATION
	@${MKDIR} ${PREFIX}/www/postfixadmin/ADDITIONS
	@${MKDIR} ${PREFIX}/www/postfixadmin/css
	@${MKDIR} ${PREFIX}/www/postfixadmin/admin
	@${MKDIR} ${PREFIX}/www/postfixadmin/images
	@${MKDIR} ${PREFIX}/www/postfixadmin/languages
	@${MKDIR} ${PREFIX}/www/postfixadmin/templates
	@${MKDIR} ${PREFIX}/www/postfixadmin/users
	@${INSTALL_DATA} ${WRKSRC}/*.php ${PREFIX}/www/postfixadmin
	@${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/www/postfixadmin
	@${INSTALL_DATA} ${WRKSRC}/*.TXT ${PREFIX}/www/postfixadmin
	@${INSTALL_DATA} ${WRKSRC}/VIRTUAL_VACATION/* ${PREFIX}/www/postfixadmin/VIRTUAL_VACATION
	@${INSTALL_DATA} ${WRKSRC}/ADDITIONS/* ${PREFIX}/www/postfixadmin/ADDITIONS
	@${INSTALL_DATA} ${WRKSRC}/css/* ${PREFIX}/www/postfixadmin/css
	@${INSTALL_DATA} ${WRKSRC}/admin/* ${PREFIX}/www/postfixadmin/admin
	@${INSTALL_DATA} ${WRKSRC}/images/* ${PREFIX}/www/postfixadmin/images
	@${INSTALL_DATA} ${WRKSRC}/languages/* ${PREFIX}/www/postfixadmin/languages
	@${INSTALL_DATA} ${WRKSRC}/templates/* ${PREFIX}/www/postfixadmin/templates
	@${INSTALL_DATA} ${WRKSRC}/users/* ${PREFIX}/www/postfixadmin/users
	@[ -f ${PREFIX}/www/postfixadmin/config.inc.php ] || \
		${CP} ${PREFIX}/www/postfixadmin/config.inc.php.sample \
			${PREFIX}/www/postfixadmin/config.inc.php

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

post-install:
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/postfixadmin
	@${CHMOD} 640 ${PREFIX}/www/postfixadmin/*.php ${PREFIX}/www/postfixadmin/css/*.css
	@${CHMOD} 640 ${PREFIX}/www/postfixadmin/admin/*.php
	@${CHMOD} 640 ${PREFIX}/www/postfixadmin/users/*.php
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
