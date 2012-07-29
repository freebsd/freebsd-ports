# Ports collection makefile for:	pear-Math_BigInteger
# Date created:				26 July 2011
# Whom:					Piotr Rybicki <meritus@innervision.pl>
#
# $FreeBSD$
#

PORTNAME=	Math_BigInteger
PORTVERSION=	1.0.0
CATEGORIES=	math pear

MAINTAINER=	meritus@innervision.pl
COMMENT=	Pure-PHP arbitrary precision integer arithmetic library

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

CATEGORY=	Math
FILES=		BigInteger.php

USE_PHP=	pcre

EXAMPLES=	demo/benchmark.php demo/demo.php
_EXAMPLESDIR=

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
