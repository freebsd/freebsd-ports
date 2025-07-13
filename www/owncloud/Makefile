PORTNAME=	owncloud
PORTVERSION=	10.15.3
CATEGORIES=	www
MASTER_SITES=	https://download.owncloud.com/server/stable/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Personal cloud which runs on your own server
WWW=		https://owncloud.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe php:flavors,web tar:bzip2
USE_PHP=	bz2 ctype curl dom fileinfo filter gd iconv intl mbstring pdo posix session simplexml xml xmlreader xmlwriter xsl zip zlib

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/owncloud

OWNCLOUD_USER?=	${WWWOWN}
OWNCLOUD_GROUP?=${WWWGRP}

PLIST_SUB=	OWNCLOUD_USER=${OWNCLOUD_USER} \
		OWNCLOUD_GROUP=${OWNCLOUD_GROUP}
SUB_FILES=	pkg-message newsyslog

OPTIONS_DEFINE=	EXAMPLES EXIF LDAP SMB
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=EXIF LDAP MYSQL SMB
EXIF_DESC=	Image rotation support

EXIF_USE=	PHP=exif
LDAP_USE=	PHP=ldap
MYSQL_USE=	PHP=pdo_mysql
PGSQL_USE=	PHP=pdo_pgsql
SMB_RUN_DEPENDS=${PECL_PKGNAMEPREFIX}smbclient>=0.8.0:net/pecl-smbclient@${PHP_FLAVOR}
SQLITE_USE=	PHP=pdo_sqlite

post-patch:
	@${FIND} ${WRKSRC} -type d -empty -delete
	@${FIND} ${WRKSRC} -type d -name .github | ${XARGS} ${RM} -r

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/
	${MKDIR} -m 0755 ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/data

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKDIR}/newsyslog ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
