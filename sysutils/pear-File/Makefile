# Ports collection makefile for:  pear-File
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	File
DISTVERSION=	1.1.0RC4
PORTEPOCH=	1
CATEGORIES=	sysutils www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR common file and directory routines

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

FILES=		File.php File/Util.php File/CSV.php
TESTS=		parser.php test.csv FileTest.php CSV/001.phpt CSV/001.csv \
		CSV/002.phpt CSV/002.csv CSV/003.phpt CSV/003.csv CSV/004.phpt \
		CSV/004.csv CSV/005.phpt CSV/005.csv CSV/tests.txt

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 430
IGNORE=		"You need PHP 4.3.0 or later to install PEAR::File"
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
