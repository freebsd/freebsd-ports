PORTNAME=	Log
PORTVERSION=	1.14.6
CATEGORIES=	sysutils www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR logging utilities
WWW=		https://pear.php.net/package/Log \
		https://github.com/pear/Log

LICENSE=	MIT

USES=		pear

NO_ARCH=	yes

OPTIONS_DEFINE=	PEAR_DB PEAR_MAIL PEAR_MDB2 PHP_SQLITE
PEAR_DB_DESC=	PEAR::DB support
PEAR_MAIL_DESC=	PEAR::Mail support
PEAR_MDB2_DESC=	PEAR::MDB2 support
PHP_SQLITE_DESC=PHP sqlite support

PEAR_DB_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}DB>=1.3:databases/pear-DB@${PHP_FLAVOR}
PEAR_MAIL_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Mail>=0:mail/pear-Mail@${PHP_FLAVOR}
PEAR_MDB2_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}MDB2>=2.0.0:databases/pear-MDB2@${PHP_FLAVOR}
PHP_SQLITE_USE=		PHP=sqlite3
PHP_SQLITE_USES=	php

.include <bsd.port.mk>
