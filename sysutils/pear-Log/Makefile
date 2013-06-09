# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	Log
PORTVERSION=	1.12.7
CATEGORIES=	sysutils www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR logging utilities

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	yes
PEAR_AUTOINSTALL=	yes

LATEST_LINK=	pear-Log
OPTIONS_DEFINE=	PEAR_DB PEAR_MDB2 PEAR_MAIL PEAR_SQLITE
PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB2_DESC=	PEAR::MDB2 support
PEAR_MAIL_DESC=	PEAR::Mail support
PHP_SQLITE_DESC=	PHP sqlite support (php5 only)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_DB}
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if ${PORT_OPTIONS:MPEAR_MDB2}
BUILD_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if ${PORT_OPTIONS:MPEAR_MAIL}
BUILD_DEPENDS+=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail
.endif

.if ${PORT_OPTIONS:MPHP_SQLITE}
USE_PHP+=	sqlite
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
