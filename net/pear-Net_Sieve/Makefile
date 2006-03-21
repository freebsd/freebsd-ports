# Ports collection makefile for:  pear-Net_Sieve
# Date created:			  25 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_Sieve
PORTVERSION=	1.1.2
CATEGORIES=	net www pear

MAINTAINER=	amistry@am-productions.biz
COMMENT=	PEAR class to handle talking to timsieved

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Sieve.php
TESTS=		test_sieve.php
_TESTSDIR=	.

PLIST_FILES=	share/pear/.registry/net_sieve.reg

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
