# $FreeBSD$

PORTNAME=	owncloud
PORTVERSION=	8.2.0
CATEGORIES=	www
MASTER_SITES=	http://download.owncloud.org/community/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Personal cloud which runs on your own server

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING-AGPL

USES=		cpe tar:bzip2
USE_PHP=	bz2 ctype curl dom fileinfo filter gd hash iconv json \
		mbstring pdo posix session simplexml xml xmlreader xmlwriter \
		xsl wddx zip zlib
WANT_PHP_WEB=	yes
USE_OPENSSL=	yes

OWNCLOUD_USERNAME?=	${WWWOWN}
OWNCLOUD_GROUPNAME?=	${WWWGRP}

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	OWNCLOUD_USERNAME=${OWNCLOUD_USERNAME} \
		OWNCLOUD_GROUPNAME=${OWNCLOUD_GROUPNAME}

OPTIONS_DEFINE=	EXIF LDAP MP3INFO SSL
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	EXIF LDAP MP3INFO MYSQL SSL

EXIF_DESC=	Image rotation support
MP3INFO_DESC=	MP3 ID3 tags support

EXIF_USE=	PHP=exif
LDAP_USE=	PHP=ldap
MP3INFO_BUILD_DEPENDS=	mp3info:${PORTSDIR}/audio/mp3info
MP3INFO_RUN_DEPENDS=	${MP3INFO_BUILD_DEPENDS}
MYSQL_USE=	MYSQL=client PHP=mysql,pdo_mysql
PGSQL_USES=	pgsql
PGSQL_USE=	PHP=pdo_pgsql,pgsql
SQLITE_USE=	PHP=pdo_sqlite,sqlite3
SSL_USE=	PHP=openssl

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1002000
WITH_OPENSSL_PORT=	yes
.endif

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data
	${CHMOD} +x ${STAGEDIR}${WWWDIR}/occ

.include <bsd.port.mk>
