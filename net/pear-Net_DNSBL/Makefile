# Ports collection makefile for:  pear-Net_DNSBL
# Date created:			  02 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_DNSBL
PORTVERSION=	1.0.0
CATEGORIES=	net pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR DNSBL Checker

BUILD_DEPENDS=	${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite \
		${PEARDIR}/Net/CheckIP.php:${PORTSDIR}/net/pear-Net_CheckIP \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

CATEGORY=	Net
FILES=		DNSBL.php DNSBL/SURBL.php
TESTS=		testNetDNSBL.php testNetDNSBLSURBL.php

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 436
IGNORE=		"You need PHP 4.3.6 or later to install PEAR::Net_DNSBL"
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
