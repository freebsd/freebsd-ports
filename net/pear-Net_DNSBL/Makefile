# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Net_DNSBL
PORTVERSION=	1.3.7
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR DNSBL Checker

BUILD_DEPENDS=	${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite \
		${PEARDIR}/Net/CheckIP.php:${PORTSDIR}/net/pear-Net_CheckIP \
		${PEARDIR}/Net/DNS/RR/A.php:${PORTSDIR}/dns/pear-Net_DNS \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2
RUN_DEPENDS:=	${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite \
		${PEARDIR}/Net/CheckIP.php:${PORTSDIR}/net/pear-Net_CheckIP \
		${PEARDIR}/Net/DNS/RR/A.php:${PORTSDIR}/dns/pear-Net_DNS \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2

USE_PHP=	yes
USES=	pear

PORTSCOUT=	skipv:1.3.0a1

.include <bsd.port.mk>
