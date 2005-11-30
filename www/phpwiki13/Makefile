# New ports collection makefile for:	phpwiki
# Date created:		09.Oct 2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	phpwiki
PORTVERSION=	1.3.11p1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpwiki

MAINTAINER=	babak@farrokhi.net
COMMENT=	A PHP WikiWikiWeb

CONFLICTS+=	phpwiki-1.2*

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ctype pcre posix session tokenizer xml zlib mysql
.if defined(WITH_CDB) || defined(WITH_DB4) || defined(WITH_GDBM) || defined(WITH_INIFILE)
USE_PHP+=	dba
.endif
.endif

NO_BUILD=	YES
PHP4_PORT?=	www/mod_php4
PHPWIKI?=	www/data-dist/phpwiki
PLIST_SUB+=	PHPWIKI=${PHPWIKI}
ROOTFILES=	GoogleSearch.wsdl PhpWiki.wsdl RPC2.php SOAP.php \
		configurator.php favicon.ico getimg.php gforge.php \
		index.php passencrypt.php wiki
ROOTDIRS=	config doc lib locale pgsrc schemas tests themes uploads
DOCFILES=	INSTALL LICENSE README TODO UPGRADING

do-configure:

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
.endif

.include <bsd.port.mk>
