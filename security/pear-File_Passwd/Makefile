# Created by: Antonio Carlos Venancio Junior <antonio@inf.ufsc.br>
# $FreeBSD$

PORTNAME=	File_Passwd
PORTVERSION=	1.1.7
CATEGORIES=	security pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class to manipulate many kinds of password files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

LATEST_LINK=	pear-File_Passwd
OPTIONS_DEFINE=	PEAR_CRYPT_CHAP
PEAR_CRYPT_CHAP_DESC=	PEAR::Crypt_CHAP support

CATEGORY=	File
FILES=		Passwd.php Passwd/Common.php Passwd/Unix.php Passwd/Cvs.php \
		Passwd/Smb.php Passwd/Authbasic.php Passwd/Authdigest.php \
		Passwd/Custom.php
TESTS=		testsuite.php test_file_passwd.php test_common.php test_unix.php \
		test_smb.php test_cvs.php test_authbasic.php test_authdigest.php \
		test_custom.php README.txt common.txt passwd.unix.txt \
		passwd.cvs.txt passwd.smb.txt passwd.authbasic.txt \
		passwd.authdigest.txt passwd.custom.txt

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPEAR_CRYPT_CHAP}
RUN_DEPENDS+=	${PEARDIR}/Crypt/CHAP.php:${PORTSDIR}/security/pear-Crypt_CHAP
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
