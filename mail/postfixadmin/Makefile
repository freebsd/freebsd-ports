# New ports collection makefile for:    postfixadmin
# Date created:                         23 October 2003
# Whom:                                 Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	postfixadmin
PORTVERSION=	2.1.0
PORTREVISION=	3
CATEGORIES=	mail www
MASTER_SITES=	http://high5.net/postfixadmin/ \
		http://sce-tindy.tecnik93.com/FreeBSD/ports/${PORTNAME}/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	PHP web-based management tool for Postfix virtual domains and users

WANT_PHP_PEAR=	yes
USE_PHP=	pcre session
NO_BUILD=	yes
USE_APACHE=	1.3+

SUB_FILES+=	pkg-message

OPTIONS=	MYSQL "Use MySQL to store config data" on
OPTIONS+=	PGSQL "Use PostgresQL to store config data" off

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	postfix>=2[0-9]*:${PORTSDIR}/mail/postfix

.ifndef(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.ifdef(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.ifdef(WITHOUT_MYSQL) && !defined(WITH_PGSQL)
IGNORE=	needs at least one database backend
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
# DO NOT DELETE
