PORTNAME=	Net_Vpopmaild
PORTVERSION=	0.3.2
CATEGORIES=	net mail pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR Class for accessing Vpopmail's vpopmaild daemon
WWW=		https://pear.php.net/package/Net_Vpopmaild

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR} \
		${PEARDIR}/Log.php:sysutils/pear-Log@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR} \
		${PEARDIR}/Log.php:sysutils/pear-Log@${PHP_FLAVOR}

USES=		pear

.include <bsd.port.mk>
