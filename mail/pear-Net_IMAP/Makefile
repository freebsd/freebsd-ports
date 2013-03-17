# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	Net_IMAP
PORTVERSION=	1.1.0
CATEGORIES=	mail net pear

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	PEAR class that provides an implementation of the IMAP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL
RUN_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
