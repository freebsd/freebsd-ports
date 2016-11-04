# Created by: Antonio Carlos Venancio Junior <antonio@inf.ufsc.br>
# $FreeBSD$

PORTNAME=	File_Passwd
PORTVERSION=	1.1.7
CATEGORIES=	security pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR class to manipulate many kinds of password files

USES=	pear

OPTIONS_DEFINE=	PEAR_CRYPT_CHAP
PEAR_CRYPT_CHAP_DESC=	PEAR::Crypt_CHAP support

PEAR_CRYPT_CHAP_RUN_DEPENDS=	${PEARDIR}/Crypt/CHAP.php:security/pear-Crypt_CHAP

.include <bsd.port.mk>
