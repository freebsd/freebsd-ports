PORTNAME=	File_SMBPasswd
PORTVERSION=	1.0.3
CATEGORIES=	security www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR class for managing SAMBA style password files
WWW=		https://pear.php.net/package/File_SMBPasswd

BUILD_DEPENDS=	${PEARDIR}/Crypt/CHAP.php:security/pear-Crypt_CHAP@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Crypt/CHAP.php:security/pear-Crypt_CHAP@${PHP_FLAVOR}

USES=		pear php
IGNORE_WITH_PHP=	84

.include <bsd.port.mk>
