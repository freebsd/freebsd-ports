# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	Net_IMAP
PORTVERSION=	1.1.3
CATEGORIES=	mail net pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class that provides an implementation of the IMAP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL
RUN_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL

USES=	pear

.include <bsd.port.mk>
