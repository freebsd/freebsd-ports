# New ports collection makefile for:	phpwiki
# Date created:		09.Oct 2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	phpwiki
PORTVERSION=	1.3.12p2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpwiki

MAINTAINER=	babak@farrokhi.net
COMMENT=	A PHP WikiWikiWeb

CONFLICTS+=	phpwiki-1.2*
LATEST_LINK=	phpwiki13

USE_PHP=	ctype pcre posix session tokenizer xml zlib

NO_BUILD=	YES
PHPWIKI?=	www/data-dist/phpwiki
PLIST_SUB+=	PHPWIKI=${PHPWIKI}
SUB_FILES=	pkg-message
ROOTFILES=	GoogleSearch.wsdl PhpWiki.wsdl RPC2.php SOAP.php \
		configurator.php favicon.ico getimg.php gforge.php \
		index.php passencrypt.php wiki
ROOTDIRS=	config lib locale pgsrc schemas tests themes uploads
DOCFILES=	INSTALL LICENSE README TODO UPGRADING

OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off \
		DB4   "Use Berkeley DB4 backend" off

.if exists(${LOCALBASE}/etc/php.conf)
.include "${LOCALBASE}/etc/php.conf"
.endif

.if defined(PHP_VER) && ${PHP_VER} == 5
OPTIONS+=	SQLITE "Use SQLite backend" off
.endif

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

.if defined(WITH_DB4)
USE_PHP+=	dba
.endif

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_SQLITE)
USE_PHP+=	sqlite
.endif

do-install:
	-${MKDIR} ${PREFIX}/${PHPWIKI}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPWIKI}
	@(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${PREFIX}/${PHPWIKI}/ )
.for i in ${ROOTDIRS}
	@(cd ${WRKSRC} && ${CP} -R ${i} ${PREFIX}/${PHPWIKI}/ )
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
	@(cd ${WRKSRC} && ${CP} -R doc/* ${DOCSDIR}/ )
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
