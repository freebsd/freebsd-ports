# New ports collection makefile for:    postfixadmin
# Date created:                         23 October 2003
# Whom:                                 Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	postfixadmin
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://high5.net/postfixadmin/ \
		http://high5.net/postfixadmin/download.php?file=
EXTRACT_SUFX=	.tgz

MAINTAINER=	rob@debank.tv
COMMENT=	PHP frontend to postfix and mySQL

WANT_PHP_PEAR=	yes
NO_BUILD=	yes

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
FETCH_CMD?=	/usr/bin/fetch -AR

.if defined (WITH_PGSQL)
USE_PHP=	pgsql
.else
USE_PHP=	mysql
.endif

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
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
