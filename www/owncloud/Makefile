# $FreeBSD$

PORTNAME=	owncloud
PORTVERSION=	5.0.13
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://download.owncloud.org/community/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Personal cloud which runs on your own server

LICENSE=	AGPLv3

BUILD_DEPENDS=	mp3info:${PORTSDIR}/audio/mp3info
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PHP=	ctype curl dom fileinfo filter gd hash iconv json ldap \
		mbstring openssl pdo session simplexml xml xmlreader \
		xsl wddx zip zlib
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE
MYSQL_USE=	MYSQL=client PHP=mysql,pdo_mysql
PGSQL_USE=	PGSQL=yes PHP=pdo_pgsql,pgsql
SQLITE_USE=	PHP=pdo_sqlite,sqlite3 SQLITE=yes

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
