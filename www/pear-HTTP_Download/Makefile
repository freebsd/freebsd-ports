# Ports collection makefile for:  pear-HTTP_Download
# Date created:			  17 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Download
PORTVERSION=	1.0.0.r3
CATEGORIES=	www devel pear
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/RC/}

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class to send HTTP downloads

BUILD_DEPENDS=	${PEARDIR}/HTTP/Header.php:${PORTSDIR}/www/pear-HTTP_Header
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

LATEST_LINK=	pear-HTTP_Download
OPTIONS=	PEAR_ARCHIVE_TAR "PEAR::Archive_Tar support" off

CATEGORY=	HTTP
FILES=		Download.php Download/PgLOB.php
TESTS=		send.php testcase.php data.txt

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 420
IGNORE=		"You need PHP 4.2.0 or later to install PEAR::HTTP_Download"
.endif

.if defined(WITH_PEAR_ARCHIVE_TAR)
BUILD_DEPENDS+=	${PEARDIR}/Archive/Tar.php:${PORTSDIR}/archivers/pear-Archive_Tar
.endif

do-build:
	${NADA}

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
