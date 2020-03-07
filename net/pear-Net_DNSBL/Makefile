# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Net_DNSBL
PORTVERSION=	1.3.7
PORTREVISION=	1
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR DNSBL Checker

LICENSE=	PHP30

BUILD_DEPENDS=	${PEARDIR}/Cache/Lite.php:sysutils/pear-Cache_Lite@${PHP_FLAVOR} \
		${PEARDIR}/Net/CheckIP.php:net/pear-Net_CheckIP@${PHP_FLAVOR} \
		${PEARDIR}/Net/DNS2.php:dns/pear-Net_DNS2@${PHP_FLAVOR} \
		${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2@${PHP_FLAVOR}
RUN_DEPENDS:=	${PEARDIR}/Cache/Lite.php:sysutils/pear-Cache_Lite@${PHP_FLAVOR} \
		${PEARDIR}/Net/CheckIP.php:net/pear-Net_CheckIP@${PHP_FLAVOR} \
		${PEARDIR}/Net/DNS2.php:dns/pear-Net_DNS2@${PHP_FLAVOR} \
		${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2@${PHP_FLAVOR}

USES=		pear

PORTSCOUT=	skipv:1.3.0a1

.include <bsd.port.mk>
