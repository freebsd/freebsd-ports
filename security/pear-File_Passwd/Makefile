# Ports collection makefile for:  pear-File_Passwd
# Date created:			  09 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	File_Passwd
PORTVERSION=	1.1.3
CATEGORIES=	security pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class to manipulate many kinds of password files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-File_Passwd
OPTIONS=	PEAR_CRYPT_CHAP "PEAR::Crypt_CHAP support" off

CATEGORY=	File
FILES=		Passwd.php Passwd/Common.php Passwd/Unix.php Passwd/Cvs.php \
		Passwd/Smb.php Passwd/Authbasic.php Passwd/Authdigest.php \
		Passwd/Custom.php
TESTS=		testsuite.php test_file_passwd.php test_common.php test_unix.php \
		test_smb.php test_cvs.php test_authbasic.php test_authdigest.php \
		test_custom.php README.txt common.txt passwd.unix.txt passwd.cvs.txt \
		passwd.smb.txt passwd.authbasic.txt passwd.authdigest.txt \
		passwd.custom.txt

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_CRYPT_CHAP)
RUN_DEPENDS+=	${PEARDIR}/Crypt/CHAP.php:${PORTSDIR}/security/pear-Crypt_CHAP
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
