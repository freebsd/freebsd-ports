PORTNAME=	Net_IMAP
PORTVERSION=	1.1.4
CATEGORIES=	mail net pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR class that provides an implementation of the IMAP protocol
WWW=		https://pear.php.net/package/Net_IMAP \
		https://github.com/pear/Net_IMAP

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Auth_SASL>=1.0.2:security/pear-Auth_SASL@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Net_Socket>=1.0.8:net/pear-Net_Socket@${PHP_FLAVOR}

USES=		pear

NO_ARCH=	yes

.include <bsd.port.mk>
