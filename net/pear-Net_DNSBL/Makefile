# Ports collection makefile for:  pear-Net_DNSBL
# Date created:			  02 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_DNSBL
PORTVERSION=	1.3.6
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR DNSBL Checker

BUILD_DEPENDS=	${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite \
		${PEARDIR}/Net/CheckIP.php:${PORTSDIR}/net/pear-Net_CheckIP \
		${PEARDIR}/Net/DNS/RR/A.php:${PORTSDIR}/dns/pear-Net_DNS \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite \
		${PEARDIR}/Net/CheckIP.php:${PORTSDIR}/net/pear-Net_CheckIP \
		${PEARDIR}/Net/DNS/RR/A.php:${PORTSDIR}/dns/pear-Net_DNS \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request

USE_PHP=	yes

PEAR_AUTOINSTALL=	yes

PORTSCOUT=	skipv:1.3.0a1

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
