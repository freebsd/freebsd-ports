PORTNAME=	ingo
PORTVERSION=	3.2.16
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde email filter rules manager
WWW=		https://www.horde.org/apps/ingo/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=80 81 82

# Optional but we want it
RUN_DEPENDS+=	${PEARDIR}/Net/Sieve.php:net/pear-Net_Sieve@${PHP_FLAVOR} \
		${PEARDIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR}

USES=		horde php cpe
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
USE_PHP=	gettext

CONFLICTS_INSTALL=	php*-horde-ingo

.include <bsd.port.mk>
