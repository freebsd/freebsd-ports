# $FreeBSD$

PORTNAME=	ingo
PORTVERSION=	3.2.7
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde email filter rules manager

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	horde cpe
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
RUN_DEPENDS+=	${PEARDIR}/Net/Sieve.php:${PORTSDIR}/net/pear-Net_Sieve \
		${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket

.include <bsd.port.mk>
