# New ports collection makefile for:	pear-Crypt_MicroID
# Date created:		2008-09-22
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt_MicroID
PORTVERSION=	0.1.0
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP MicroID library.

BUILD_DEPENDS+=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS+=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		Crypt/MicroID.php Crypt/MicroID/AlgorithmNotFoundException.php
TESTS=		001-generate.phpt 002-verify.phpt tests-config.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
