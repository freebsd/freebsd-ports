# $FreeBSD$

PORTNAME=	owncloud
PORTVERSION=	6.0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.owncloud.org/community/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Personal cloud which runs on your own server

LICENSE=	AGPLv3

BUILD_DEPENDS=	mp3info:${PORTSDIR}/audio/mp3info
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PHP=	bz2 ctype curl dom exif fileinfo filter gd hash iconv json \
		ldap mbstring openssl pdo session simplexml xml xmlreader \
		xsl wddx zip zlib
WANT_PHP_WEB=	yes

OWNCLOUD_USERNAME?=	www
OWNCLOUD_GROUPNAME?=	${OWNCLOUD_USERNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	OWNCLOUD_USERNAME=${OWNCLOUD_USERNAME} \
		OWNCLOUD_GROUPNAME=${OWNCLOUD_GROUPNAME}

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE
MYSQL_USE=	MYSQL=client PHP=mysql,pdo_mysql
PGSQL_USE=	PGSQL=yes PHP=pdo_pgsql,pgsql
SQLITE_USE=	PHP=pdo_sqlite,sqlite3

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
