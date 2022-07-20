PORTNAME=	File_SMBPasswd
PORTVERSION=	1.0.3
CATEGORIES=	security www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR class for managing SAMBA style password files

BUILD_DEPENDS=	${PEARDIR}/Crypt/CHAP.php:security/pear-Crypt_CHAP@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Crypt/CHAP.php:security/pear-Crypt_CHAP@${PHP_FLAVOR}

USES=		pear php
USE_PHP=	hash

.include <bsd.port.mk>
