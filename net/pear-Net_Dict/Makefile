PORTNAME=	Net_Dict
PORTVERSION=	1.0.7
CATEGORIES=	net www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR interface to the DICT protocol
WWW=		https://pear.php.net/package/Net_Dict

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR} \
		${PEARDIR}/Cache.php:sysutils/pear-Cache@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR} \
		${PEARDIR}/Cache.php:sysutils/pear-Cache@${PHP_FLAVOR}

USES=		pear

.include <bsd.port.mk>
