PORTNAME=	snappymail
DISTVERSION=	2.36.4
CATEGORIES=	mail www
MASTER_SITES=	https://github.com/the-djmaze/snappymail/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Simple, modern, lightweight & fast web-based email client
WWW=		https://snappymail.eu/

LICENSE=	AGPLv3

RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}APCu>0:devel/pecl-APCu@${PHP_FLAVOR} \
		${PECL_PKGNAMEPREFIX}uuid>0:devel/pecl-uuid@${PHP_FLAVOR} \
		${PECL_PKGNAMEPREFIX}xxtea>0:security/pecl-xxtea@${PHP_FLAVOR}

USES=		php:web,flavors
USE_PHP=	ctype curl dom fileinfo gd iconv intl mbstring phar simplexml \
		sodium tidy xml zip zlib

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_SUB=	VER="${PORTVERSION}" \
		WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"

OPTIONS_DEFINE=		GNUPG LDAP MYSQL PGSQL REDIS SQLITE3
OPTIONS_DEFAULT=	GNUPG LDAP MYSQL PGSQL REDIS SQLITE3

GNUPG_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}gnupg>0:security/pecl-gnupg@${PHP_FLAVOR}
LDAP_USE=		PHP=ldap
MYSQL_USE=		PHP=pdo_mysql
PGSQL_USE=		PHP=pdo_pgsql
REDIS_USE=		PHP=redis
SQLITE3_USE=		PHP=pdo_sqlite

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${RM} -r ${STAGEDIR}${WWWDIR}/data
	${MKDIR} ${STAGEDIR}${WWWDIR}/data

.include <bsd.port.mk>
