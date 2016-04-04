# $FreeBSD$

PORTNAME=	Horde_Mail_Autoconfig
PORTVERSION=	1.0.3
CATEGORIES=	mail www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Mail Autoconfiguration

USES=	horde
USE_HORDE_RUN=	Horde_Exception \
		Horde_Http \
		Horde_Imap_Client \
		Horde_Mail \
		Horde_Smtp

RUN_DEPENDS+=	${PEARDIR}/Net/DNS2.php:dns/pear-Net_DNS2

.include <bsd.port.mk>
