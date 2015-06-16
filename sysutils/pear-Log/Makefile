# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	Log
PORTVERSION=	1.12.9
CATEGORIES=	sysutils www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR logging utilities

LICENSE=	MIT

USES=		pear
USE_PHP=	yes

LATEST_LINK=	pear-Log
OPTIONS_DEFINE=	PEAR_DB PEAR_MDB2 PEAR_MAIL PEAR_SQLITE
PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB2_DESC=	PEAR::MDB2 support
PEAR_MAIL_DESC=	PEAR::Mail support
PHP_SQLITE_DESC=	PHP sqlite support (php5 only)

PEAR_DB_BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
PEAR_MDB2_BUILD_DEPENDS=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
PEAR_MAIL_BUILD_DEPENDS=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail
PHP_SQLITE_USE=	PHP=sqlite

.include <bsd.port.mk>
