# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	Log
PORTVERSION=	1.13.1
CATEGORIES=	sysutils www pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR logging utilities

LICENSE=	MIT

USES=		pear

OPTIONS_DEFINE=	PEAR_DB PEAR_MDB2 PEAR_MAIL PEAR_SQLITE
PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB2_DESC=	PEAR::MDB2 support
PEAR_MAIL_DESC=	PEAR::Mail support
PHP_SQLITE_DESC=	PHP sqlite support (php5 only)

PEAR_DB_BUILD_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB
PEAR_MDB2_BUILD_DEPENDS=	${PEARDIR}/MDB2.php:databases/pear-MDB2
PEAR_MAIL_BUILD_DEPENDS=	${PEARDIR}/Mail.php:mail/pear-Mail
PHP_SQLITE_USE=	PHP=sqlite

.include <bsd.port.mk>
