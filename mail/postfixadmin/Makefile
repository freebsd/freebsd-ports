# Created by: Rob Evers <rob@debank.tv>
# $FreeBSD$

PORTNAME=	postfixadmin
PORTVERSION=	2.3.7
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	tabmow@freenode.net
COMMENT=	PHP web-based management tool for Postfix virtual domains and users

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL-LICENSE.TXT

USES=		cpe
CPE_VENDOR=	postfix_admin_project
CPE_PRODUCT=	postfix_admin

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

SUB_FILES+=	pkg-message
SUB_LIST=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL MYSQLI PGSQL
MYSQLI_DESC=	MySQL 4.1+ back-end (use mysqli PHP extension)

OPTIONS_DEFAULT=	MYSQL

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

USE_PHP=	pcre session mbstring spl xmlrpc

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MMYSQLI}
USE_PHP+=	mysqli
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

WANT_PHP_WEB=	yes

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

pre-install:
	@${RM} -rf ${WRKSRC}/ADDITIONS/squirrelmail-plugin

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/VIRTUAL_VACATION
	@${MKDIR} ${STAGEDIR}${WWWDIR}/ADDITIONS
	@${MKDIR} ${STAGEDIR}${WWWDIR}/ADDITIONS/cyrus
	@${MKDIR} ${STAGEDIR}${WWWDIR}/css
	@${MKDIR} ${STAGEDIR}${WWWDIR}/admin
	@${MKDIR} ${STAGEDIR}${WWWDIR}/images
	@${MKDIR} ${STAGEDIR}${WWWDIR}/languages
	@${MKDIR} ${STAGEDIR}${WWWDIR}/model
	@${MKDIR} ${STAGEDIR}${WWWDIR}/templates
	@${MKDIR} ${STAGEDIR}${WWWDIR}/users
	(cd ${WRKSRC}/ && \
	${COPYTREE_SHARE} \*.php ${STAGEDIR}${WWWDIR} "! -name config.inc.php")
	@${CP} ${WRKSRC}/config.inc.php ${STAGEDIR}${WWWDIR}/config.inc.php.sample
	@${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${WWWDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.TXT ${STAGEDIR}${WWWDIR}
	@${INSTALL_DATA} ${WRKSRC}/css/* ${STAGEDIR}${WWWDIR}/css
	@${INSTALL_DATA} ${WRKSRC}/admin/* ${STAGEDIR}${WWWDIR}/admin
	@${INSTALL_DATA} ${WRKSRC}/images/* ${STAGEDIR}${WWWDIR}/images
	@${INSTALL_DATA} ${WRKSRC}/languages/* ${STAGEDIR}${WWWDIR}/languages
	@${INSTALL_DATA} ${WRKSRC}/model/* ${STAGEDIR}${WWWDIR}/model
	@${INSTALL_DATA} ${WRKSRC}/templates/* ${STAGEDIR}${WWWDIR}/templates
	@${INSTALL_DATA} ${WRKSRC}/users/* ${STAGEDIR}${WWWDIR}/users
	@${CP} -R ${WRKSRC}/VIRTUAL_VACATION/* ${STAGEDIR}${WWWDIR}/VIRTUAL_VACATION
	(cd ${WRKSRC}/ADDITIONS/ && \
	${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}/ADDITIONS/ "! -name squirrelmail-plugin")

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
