# $FreeBSD$

PORTNAME=	sabredav
PORTVERSION=	3.2.2
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	meyser@xenet.de
COMMENT=	WebDav, CalDav and Carddav Server/Framework written in PHP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php
USE_PHP=	dom simplexml mbstring pcre spl ctype iconv xmlwriter
USE_GITHUB=	yes
CPE_VENDOR=	fruux
GH_ACCOUNT=	fruux
GH_PROJECT=	sabre-dav

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL

MYSQL_USE=		PHP=pdo_mysql
PGSQL_USE=		PHP=pdo_pgsql
SQLITE_USE=		PHP=pdo_sqlite

post-extract:
	@${FIND} ${WRKSRC}/ -type f -name '.*' -delete

do-install:
	  @${MKDIR} ${STAGEDIR}/${WWWDIR}
	  @(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR})

.include <bsd.port.mk>
