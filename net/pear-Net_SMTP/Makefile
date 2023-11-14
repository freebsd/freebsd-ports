PORTNAME=	Net_SMTP
PORTVERSION=	1.11.1
CATEGORIES=	net mail www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR class that provides an implementation of the SMTP protocol
WWW=		https://pear.php.net/package/Net_SMTP

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Net_Socket>=1.0.7:net/pear-Net_Socket@${PHP_FLAVOR}

USES=		pear

NO_ARCH=	yes

OPTIONS_DEFINE=	PEAR_AUTH_SASL
PEAR_AUTH_SASL_DESC=	PEAR::Auth_SASL support

PEAR_AUTH_SASL_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Auth_SASL>=1.0.5:security/pear-Auth_SASL@${PHP_FLAVOR}

.include <bsd.port.mk>
