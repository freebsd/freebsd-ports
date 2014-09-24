# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	Net_Cyrus
PORTVERSION=	0.3.1
CATEGORIES=	mail net pear

MAINTAINER=	bra@fsn.hu
COMMENT=	PEAR class to administer Cyrus IMAP servers

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEARDIR}/Net/IMAP.php:${PORTSDIR}/mail/pear-Net_IMAP
RUN_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEARDIR}/Net/IMAP.php:${PORTSDIR}/mail/pear-Net_IMAP

USES=	pear

.include <bsd.port.mk>
