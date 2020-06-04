# Created by: Alonso Cardenas <acmFreeBSD.org>
# $FreeBSD$

PORTNAME=	drupal8
PORTVERSION=	8.8.7
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTNAME=	drupal-${PORTVERSION}
DIST_SUBDIR=	drupal

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Database driven web content management system (CMS)

LICENSE=	GPLv2+

USES=		php:web shebangfix
USE_PHP=	dom filter gd hash json mbstring opcache pcre pdo session \
		simplexml tokenizer xml
SHEBANG_FILES=	core/scripts/password-hash.sh

NO_ARCH=	yes
NO_BUILD=	yes
DOCS=		core/CHANGELOG.txt core/INSTALL.mysql.txt core/INSTALL.sqlite.txt \
		LICENSE.txt README.txt core/COPYRIGHT.txt core/INSTALL.pgsql.txt \
		core/INSTALL.txt core/MAINTAINERS.txt core/UPDATE.txt

OPTIONS_DEFINE=		MYSQL SQLITE3 PGSQL DOCS
OPTIONS_DEFAULT=	MYSQL

SUB_FILES+=	pkg-message

PGSQL_USES=	pgsql
PGSQL_USE=	PHP=pdo_pgsql
SQLITE3_USE=	PHP=pdo_sqlite
MYSQL_USES=	mysql
MYSQL_USE=	PHP=pdo_mysql

post-extract:
	@${MKDIR} ${WRKDIR}/DOCS
	@${MV} ${DOCS:S|^|${WRKSRC}/|} ${WRKDIR}/DOCS/

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${WWWDIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/DOCS && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
