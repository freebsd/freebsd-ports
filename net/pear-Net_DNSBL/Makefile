PORTNAME=	Net_DNSBL
PORTVERSION=	1.3.7
PORTREVISION=	2
CATEGORIES=	net pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR DNSBL Checker
WWW=		https://pear.php.net/package/Net_DNSBL

LICENSE=	PHP30

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Cache_Lite>=1.4.1:sysutils/pear-Cache_Lite@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}HTTP_Request2>=2.0.0:www/pear-HTTP_Request2@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Net_DNS21>=1.0.0:dns/pear-Net_DNS21@${PHP_FLAVOR}

USES=		pear

NO_ARCH=	yes

.include <bsd.port.mk>
