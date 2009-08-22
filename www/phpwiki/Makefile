# New ports collection makefile for:	phpwiki
# Date created:		09.Oct 2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	phpwiki
PORTVERSION=	1.2.10
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/PhpWiki%201.2%20%28stable%29/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PHP WikiWikiWeb

CONFLICTS=	phpwiki-1.3*

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ctype gettext pcre posix session tokenizer xml zlib
.endif

NO_BUILD=	YES
PHPWIKI?=	www/phpwiki
PLIST_SUB+=	PHPWIKI=${PHPWIKI}
USERFILES=	admin.php lib/config.php
ROOTFILES=	admin.php-dist index.php
ROOTDIRS=	admin images lib locale pgsrc schemas templates
DOCFILES=	CREDITS ChangeLog DBLIB.txt HISTORY INSTALL \
		INSTALL.flatfile INSTALL.mSQL INSTALL.mssql \
		INSTALL.mysql INSTALL.pgsql LICENSE README \
		UPGRADING.readme

NO_LATEST_LINK=	yes

do-configure:
.for i in ${USERFILES}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}-dist
.endfor

do-install:
	-${MKDIR} ${PREFIX}/${PHPWIKI}/lib
	-${MKDIR} ${PREFIX}/${PHPWIKI}/pages
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPWIKI}/pages
	@${CHMOD} 755 ${PREFIX}/${PHPWIKI}/pages
	@(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${PREFIX}/${PHPWIKI}/ )
.for i in ${ROOTDIRS}
	@(cd ${WRKSRC} && ${CP} -R ${i} ${PREFIX}/${PHPWIKI}/ )
.endfor
.for i in ${USERFILES}
	@if ${TEST} ! -f ${PREFIX}/${PHPWIKI}/${i} ; then \
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
