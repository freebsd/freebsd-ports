# Ports collection makefile for:  pear-Log
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Log
PORTVERSION=	1.12.7
CATEGORIES=	sysutils www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR logging utilities

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	yes
IGNORE_WITH_PHP=	4
PEAR_AUTOINSTALL=	yes

LATEST_LINK=	pear-Log
OPTIONS=	PEAR_DB "PEAR::DB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_Mail "PEAR::Mail support" off \
		PHP_SQLITE "PHP sqlite support (php5 only)" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB2)
BUILD_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_Mail)
BUILD_DEPENDS+=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail
.endif

.if defined(WITH_PHP_SQLITE)
USE_PHP+=	sqlite
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
