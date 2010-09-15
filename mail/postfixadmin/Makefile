# New ports collection makefile for:    postfixadmin
# Date created:                         23 October 2003
# Whom:                                 Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	postfixadmin
PORTVERSION=	2.3.2
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	tabmow@freenode.net
COMMENT=	PHP web-based management tool for Postfix virtual domains and users

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

SUB_FILES+=	pkg-message

OPTIONS=	MYSQL "MySQL back-end (use mysql PHP extension)" on
OPTIONS+=	MYSQLI "MySQL 4.1+ back-end (use mysqli PHP extension)" off
OPTIONS+=	PGSQL "PostgreSQL back-end (use pgsql PHP extension)" off

.include <bsd.port.pre.mk>

USE_PHP=	pcre session mbstring spl xmlrpc

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

pre-install:
	@${RM} -rf ${WRKSRC}/ADDITIONS/squirrelmail-plugin

do-install:
	@${MKDIR} ${PREFIX}/www/postfixadmin/VIRTUAL_VACATION
	@${MKDIR} ${PREFIX}/www/postfixadmin/ADDITIONS
	@${MKDIR} ${PREFIX}/www/postfixadmin/ADDITIONS/cyrus
	@${MKDIR} ${PREFIX}/www/postfixadmin/css
	@${MKDIR} ${PREFIX}/www/postfixadmin/admin
	@${MKDIR} ${PREFIX}/www/postfixadmin/images
	@${MKDIR} ${PREFIX}/www/postfixadmin/languages
	@${MKDIR} ${PREFIX}/www/postfixadmin/model
	@${MKDIR} ${PREFIX}/www/postfixadmin/templates
	@${MKDIR} ${PREFIX}/www/postfixadmin/users
	(cd ${WRKSRC}/ && \
	${COPYTREE_SHARE} \*.php ${PREFIX}/www/postfixadmin "! -name config.inc.php")
	@${CP} ${WRKSRC}/config.inc.php ${PREFIX}/www/postfixadmin/config.inc.php.sample
	@${CP} -n ${WRKSRC}/config.inc.php ${PREFIX}/www/postfixadmin/config.inc.php
	@${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/www/postfixadmin
	@${INSTALL_DATA} ${WRKSRC}/*.TXT ${PREFIX}/www/postfixadmin
	@${INSTALL_DATA} ${WRKSRC}/css/* ${PREFIX}/www/postfixadmin/css
	@${INSTALL_DATA} ${WRKSRC}/admin/* ${PREFIX}/www/postfixadmin/admin
	@${INSTALL_DATA} ${WRKSRC}/images/* ${PREFIX}/www/postfixadmin/images
	@${INSTALL_DATA} ${WRKSRC}/languages/* ${PREFIX}/www/postfixadmin/languages
	@${INSTALL_DATA} ${WRKSRC}/model/* ${PREFIX}/www/postfixadmin/model
	@${INSTALL_DATA} ${WRKSRC}/templates/* ${PREFIX}/www/postfixadmin/templates
	@${INSTALL_DATA} ${WRKSRC}/users/* ${PREFIX}/www/postfixadmin/users
	@${CP} -R ${WRKSRC}/VIRTUAL_VACATION/* ${PREFIX}/www/postfixadmin/VIRTUAL_VACATION
	(cd ${WRKSRC}/ADDITIONS/ && \
	${COPYTREE_SHARE} \* ${PREFIX}/www/postfixadmin/ADDITIONS/ "! -name squirrelmail-plugin")

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

post-install:
	@if [ ! -f ${PREFIX}/www/postfixadmin/config.inc.php ]; then \
		${CP} -p ${PREFIX}/www/postfixadmin/config.inc.php.sample ${PREFIX}/www/postfixadmin/config.inc.php ; \
	fi
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/postfixadmin
	@${CHMOD} 640 ${PREFIX}/www/postfixadmin/*.php ${PREFIX}/www/postfixadmin/css/*.css
	@${CHMOD} 640 ${PREFIX}/www/postfixadmin/admin/*.php
	@${CHMOD} 640 ${PREFIX}/www/postfixadmin/users/*.php
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
