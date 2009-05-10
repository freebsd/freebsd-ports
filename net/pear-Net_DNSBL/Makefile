# Ports collection makefile for:  pear-Net_DNSBL
# Date created:			  02 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_DNSBL
PORTVERSION=	1.3.2
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR DNSBL Checker

BUILD_DEPENDS=	${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite \
		${PEARDIR}/Net/CheckIP.php:${PORTSDIR}/net/pear-Net_CheckIP \
		${PEARDIR}/Net/DNS/RR/A.php:${PORTSDIR}/dns/pear-Net_DNS \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

CATEGORY=	Net
FILES=		Net/DNSBL.php Net/DNSBL/SURBL.php
TESTS=		AllTests.php testNetDNSBL.php testNetDNSBLSURBL.php

PORTSCOUT=	skipv:1.3.0a1

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERSION) && ${PHP_VERS} < 436
IGNORE=		need PHP 4.3.6 or later to install PEAR::Net_DNSBL
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
