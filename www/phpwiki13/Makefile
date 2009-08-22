# New ports collection makefile for:	phpwiki
# Date created:		09.Oct 2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	phpwiki
PORTVERSION=	1.3.14
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/PhpWiki%201.3%20%28current%29/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PHP WikiWikiWeb

CONFLICTS+=	phpwiki-1.2*
LATEST_LINK=	phpwiki13

USE_PHP=	ctype gettext pcre posix session tokenizer xml zlib
USE_ZIP=	yes

NO_BUILD=	YES
PHPWIKI?=	www/phpwiki
PLIST_SUB+=	PHPWIKI=${PHPWIKI}
SUB_FILES=	pkg-message
ROOTFILES=	GoogleSearch.wsdl PhpWiki.wsdl RPC2.php SOAP.php \
		configurator.php favicon.ico getimg.php gforge.php \
		index.php passencrypt.php wiki
ROOTDIRS=	config lib locale pgsrc schemas tests themes uploads
DOCFILES=	INSTALL LICENSE README TODO UPGRADING

OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off \
		DB4   "Use Berkeley DB4 backend" off \
		SQLITE "Use SQLite backend (php5 only)" off

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
