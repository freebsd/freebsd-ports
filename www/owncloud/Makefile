# $FreeBSD$

PORTNAME=	owncloud
PORTVERSION=	9.1.2
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

IGNORE_FILES=	! -name *\.orig

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	OWNCLOUD_USERNAME=${OWNCLOUD_USERNAME} \
		OWNCLOUD_GROUPNAME=${OWNCLOUD_GROUPNAME}

OPTIONS_DEFINE=	EXIF LDAP SMB SSL
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	EXIF LDAP MYSQL SMB SSL

EXIF_DESC=	Image rotation support

EXIF_USE=	PHP=exif
LDAP_USE=	PHP=ldap
MYSQL_USE=	MYSQL=client PHP=pdo_mysql
PGSQL_USES=	pgsql
PGSQL_USE=	PHP=pdo_pgsql,pgsql
SQLITE_USE=	PHP=pdo_sqlite,sqlite3
SMB_RUN_DEPENDS=	pecl-smbclient>=0.8.0:net/pecl-smbclient
SSL_USE=	PHP=openssl

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1002000
WITH_OPENSSL_PORT=	yes
.endif

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} '${IGNORE_FILES}'
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data

.include <bsd.port.mk>
