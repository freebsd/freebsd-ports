# New ports collection makefile for:	phpwiki
# Date created:		09.Oct 2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	phpwiki
PORTVERSION=	1.2.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpwiki

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A PHP WikiWikiWeb

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ctype pcre posix session tokenizer xml zlib
.endif

NO_BUILD=	YES
PHP4_PORT?=	www/mod_php4
PHPWIKI?=	www/data-dist/phpwiki
PLIST_SUB+=	PHPWIKI=${PHPWIKI}
USERFILES=	admin.php lib/config.php
ROOTFILES=	admin.php-dist index.php
ROOTDIRS=	admin images lib locale pgsrc schemas templates
DOCFILES=	CREDITS ChangeLog DBLIB.txt HISTORY INSTALL \
		INSTALL.flatfile INSTALL.mSQL INSTALL.mssql \
		INSTALL.mysql INSTALL.pgsql LICENSE README \
		UPGRADING.readme

do-configure:
.for i in ${USERFILES}
	${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}-dist
.endfor

do-install:
	-${MKDIR} ${PREFIX}/${PHPWIKI}/lib
	-${MKDIR} ${PREFIX}/${PHPWIKI}/pages
	@${CHOWN} www:www ${PREFIX}/${PHPWIKI}/pages
	@${CHMOD} 755 ${PREFIX}/${PHPWIKI}/pages
	@(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${PREFIX}/${PHPWIKI}/ )
.for i in ${ROOTDIRS}
	@(cd ${WRKSRC} && ${CP} -R ${i} ${PREFIX}/${PHPWIKI}/ )
.endfor
.for i in ${USERFILES}
	@if test ! -f ${PREFIX}/${PHPWIKI}/${i} ; then \
		${CP} ${PREFIX}/${PHPWIKI}/${i}-dist \
			${PREFIX}/${PHPWIKI}/${i}; \
	fi
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

.include <bsd.port.mk>
