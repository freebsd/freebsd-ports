# $FreeBSD$

PORTNAME=	ingo
PORTVERSION=	3.2.16
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde email filter rules manager

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe horde php
USE_PHP=	gettext
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		Horde_Auth \
		Horde_Autoloader \
		Horde_Core \
		Horde_Exception \
		Horde_Group \
		Horde_Form \
		Horde_Imap_Client \
		Horde_Mime \
		Horde_Perms \
		Horde_Share \
		Horde_Util

# Optional but we want it
RUN_DEPENDS+=	${PEARDIR}/Net/Sieve.php:net/pear-Net_Sieve@${PHP_FLAVOR} \
		${PEARDIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR}

.include <bsd.port.mk>
