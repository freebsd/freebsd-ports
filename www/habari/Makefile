# New ports collection makefile for:	habari
# Date created:				Mar 30 2008
# Whom:					Ayumi M <ayu@commun.jp>
#
# $FreeBSD$
#

PORTNAME=	habari
PORTVERSION=	0.8
CATEGORIES=	www
MASTER_SITES=	http://habariproject.org/dist/ \
		http://launchpadlibrarian.net/60087200/

MAINTAINER=	ayu@commun.jp
COMMENT=	Next-generation free software blogging platform

USE_ZIP=	yes
USE_PHP=	ctype filter hash json mbstring pcre pdo session simplexml tokenizer zlib
WANT_PHP_WEB=	yes
NO_BUILD=	yes

OPTIONS=	MYSQL "Use MySQL" on \
		PGSQL "Use PostgreSQL" off \
		SQLITE "Use SQLite" off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_PHP+=	pdo_mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pdo_pgsql
.endif

.if defined(WITH_SQLITE)
USE_PHP+=	pdo_sqlite
.endif

.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL) && !defined(WITH_SQLITE)
IGNORE=	please choose the type of database
.endif

post-patch:
.for f in doc/index.html system/classes/theme.php.orig user/cache/.gitignore
	${RM} ${WRKSRC}/${f}
.endfor

do-install:
	@${MKDIR} ${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/index.php ${WWWDIR}
.for f in system user
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${WWWDIR})
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in LICENSE NOTICE README.md doc/MIT.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} manual ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
