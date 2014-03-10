# Created by: Ayumi M <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	habari
PORTVERSION=	0.8
CATEGORIES=	www
MASTER_SITES=	http://habariproject.org/dist/ \
		http://launchpadlibrarian.net/60087200/

MAINTAINER=	ayu@commun.jp
COMMENT=	Next-generation free software blogging platform

USES=		zip
USE_PHP=	ctype filter hash json mbstring pcre pdo session simplexml tokenizer zlib
WANT_PHP_WEB=	yes
NO_BUILD=	yes

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL
OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	pdo_sqlite
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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in LICENSE NOTICE README.md doc/MIT.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} manual ${DOCSDIR})
.endif

.include <bsd.port.mk>
