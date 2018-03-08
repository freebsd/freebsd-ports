# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	Net_Cyrus
PORTVERSION=	0.3.1
CATEGORIES=	mail net pear

MAINTAINER=	bra@fsn.hu
COMMENT=	PEAR class to administer Cyrus IMAP servers

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR} \
		${PEARDIR}/Net/IMAP.php:mail/pear-Net_IMAP@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR} \
		${PEARDIR}/Net/IMAP.php:mail/pear-Net_IMAP@${PHP_FLAVOR}

USES=		pear

.include <bsd.port.mk>
