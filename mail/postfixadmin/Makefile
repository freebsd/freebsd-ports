# New ports collection makefile for:    postfixadmin
# Date created:                         23 October 2003
# Whom:                                 Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	postfixadmin
PORTVERSION=	2.1.0
PORTREVISION=	6
CATEGORIES=	mail www
MASTER_SITES=	http://high5.net/postfixadmin/ \
		http://sce-tindy.tecnik93.com/FreeBSD/ports/${PORTNAME}/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darren.pilgrim@bitfreak.org
COMMENT=	PHP web-based management tool for Postfix virtual domains and users

NO_BUILD=	yes

SUB_FILES+=	pkg-message

OPTIONS=	MYSQL "Use MySQL to store config data" on
OPTIONS+=	MYSQLI "Use MySQL 4.1+ to store config data" off
OPTIONS+=	PGSQL "Use PostgreSQL to store config data" off
OPTIONS+=	POSTFIX_LOCAL "RUN_DEPEND on postfix (OPTIONAL)" off

.include <bsd.port.pre.mk>

USE_APACHE=	1.3+
USE_PHP=	pcre session

.ifndef(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.ifdef(WITH_MYSQLI)
USE_PHP+=	mysqli
.endif

.ifdef(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.ifdef(WITHOUT_MYSQL) && !defined(WITH_MYSQLI) && !defined(WITH_PGSQL)
IGNORE=	needs at least one database backend
.endif

.ifdef(WITH_POSTFIX_LOCAL)
RUN_DEPENDS+=	postfix>=2[0-9]*:${PORTSDIR}/mail/postfix
.endif

.include "${PORTSDIR}/Mk/bsd.php.mk"

post-patch:
		${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
		@${MKDIR} ${PREFIX}/www/postfixadmin/VIRTUAL_VACATION
		@${MKDIR} ${PREFIX}/www/postfixadmin/admin
		@${MKDIR} ${PREFIX}/www/postfixadmin/images
		@${MKDIR} ${PREFIX}/www/postfixadmin/languages
		@${MKDIR} ${PREFIX}/www/postfixadmin/templates
		@${MKDIR} ${PREFIX}/www/postfixadmin/users
		@${INSTALL_DATA} ${WRKSRC}/*.TXT ${PREFIX}/www/postfixadmin
		@${INSTALL_DATA} ${WRKSRC}/*.php ${PREFIX}/www/postfixadmin
		@${INSTALL_DATA} ${WRKSRC}/*.sample ${PREFIX}/www/postfixadmin
		@${INSTALL_DATA} ${WRKSRC}/*.css ${PREFIX}/www/postfixadmin
		@${INSTALL_DATA} ${WRKSRC}/VIRTUAL_VACATION/* ${PREFIX}/www/postfixadmin/VIRTUAL_VACATION
		@${INSTALL_DATA} ${WRKSRC}/admin/* ${PREFIX}/www/postfixadmin/admin
		@${INSTALL_DATA} ${WRKSRC}/admin/.ht* ${PREFIX}/www/postfixadmin/admin
		@${INSTALL_DATA} ${WRKSRC}/images/* ${PREFIX}/www/postfixadmin/images
		@${INSTALL_DATA} ${WRKSRC}/languages/* ${PREFIX}/www/postfixadmin/languages
		@${INSTALL_DATA} ${WRKSRC}/templates/* ${PREFIX}/www/postfixadmin/templates
		@${INSTALL_DATA} ${WRKSRC}/users/* ${PREFIX}/www/postfixadmin/users
		@[ -f ${PREFIX}/www/postfixadmin/config.inc.php ] || \
			${CP} ${PREFIX}/www/postfixadmin/config.inc.php.sample \
				${PREFIX}/www/postfixadmin/config.inc.php

post-install:
		@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/postfixadmin
		@${CHMOD} 640 ${PREFIX}/www/postfixadmin/*.php ${PREFIX}/www/postfixadmin/*.css
		@${CHMOD} 640 ${PREFIX}/www/postfixadmin/admin/*.php
		@${CHMOD} 640 ${PREFIX}/www/postfixadmin/users/*.php
		@${CHMOD} 640 ${PREFIX}/www/postfixadmin/templates/*.tpl
		${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
