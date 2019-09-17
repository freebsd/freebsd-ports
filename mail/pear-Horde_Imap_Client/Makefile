# $FreeBSD$

PORTNAME=	Horde_Imap_Client
PORTVERSION=	2.29.18
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde IMAP abstraction interface

USES=	horde
USE_PHP=	hash
USE_HORDE_RUN=	Horde_Exception \
		Horde_Mail \
		Horde_Mime \
		Horde_Stream \
		Horde_Util

OPTIONS_DEFAULT=	IMAP MBSTRING SASL
OPTIONS_DEFINE=		IMAP MBSTRING SASL
IMAP_DESC=	Require PHP imap extension
MBSTRING_DESC=	Require PHP mbstring extension
SASL_DESC=	Support SASL Authentication

IMAP_USE=	PHP=imap
MBSTRING_USE=	PHP=mbstring
SASL_RUN_DEPENDS=	${PEARDIR}/Auth/SASL.php:security/pear-Auth_SASL@${PHP_FLAVOR}

.include <bsd.port.mk>
