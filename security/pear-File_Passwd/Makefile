# Ports collection makefile for:  pear-File_Passwd
# Date created:			  09 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	File_Passwd
PORTVERSION=	1.1.2
CATEGORIES=	security www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class to manipulate many kinds of password files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

LATEST_LINK=	pear-File_Passwd
OPTIONS=	PEAR_CRYPT_RC4 "PEAR::Crypt_RC4 support" off

CATEGORY=	File
FILES=		Passwd.php Passwd/Common.php Passwd/Unix.php Passwd/Cvs.php \
		Passwd/Smb.php Passwd/Authbasic.php Passwd/Authdigest.php \
		Passwd/Custom.php
TESTS=		testsuite.php test_file_passwd.php test_common.php test_unix.php \
		test_smb.php test_cvs.php test_authbasic.php test_authdigest.php \
		test_custom.php README.txt common.txt passwd.unix.txt \
		passwd.cvs.txt passwd.smb.txt passwd.authbasic.txt \
		passwd.authdigest.txt passwd.custom.txt

.if defined(WITH_PEAR_CRYPT_RC4)
RUN_DEPENDS+=	${PEARDIR}/Crypt/Rc4.php:${PORTSDIR}/security/pear-Crypt_RC4
.endif

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 406
IGNORE=		"You need PHP 4.0.6 or later to install PEAR::File_Passwd"
.endif

do-build:
	${DO_NADA}

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
