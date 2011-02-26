# Ports collection makefile for:  pear-Net_URL_Mapper
# Date created:			  2007-04-29
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net_URL_Mapper
PORTVERSION=	0.9.1
CATEGORIES=	net www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A simple and flexible way to build nice URLs for web applications.

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Mapper/Exception.php Mapper/Part.php \
		Mapper/Path.php Mapper/Part/Dynamic.php \
		Mapper/Part/Fixed.php Mapper/Part/Wildcard.php
TESTS=		ExceptionTest.php GenerationTest.php RecognitionTest.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
