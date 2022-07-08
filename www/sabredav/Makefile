PORTNAME=	sabredav
DISTVERSION=	4.4.0
CATEGORIES=	www

MAINTAINER=	meyser@xenet.de
COMMENT=	WebDav, CalDav and Carddav Server/Framework written in PHP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php
CPE_VENDOR=	sabre-io
USE_GITHUB=	yes
GH_ACCOUNT=	sabre-io
GH_PROJECT=	dav
USE_PHP=	ctype dom iconv mbstring pcre simplexml spl xmlwriter

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFAULT=	MYSQL
OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE

MYSQL_USE=	PHP=pdo_mysql
PGSQL_USE=	PHP=pdo_pgsql
SQLITE_USE=	PHP=pdo_sqlite

post-extract:
	@${FIND} ${WRKSRC}/ -type f -name '.*' -delete

do-install:
	  @${MKDIR} ${STAGEDIR}/${WWWDIR}
	  @(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR})

.include <bsd.port.mk>
