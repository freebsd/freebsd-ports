# Ports collection makefile for:  pear-Net_DIME
# Date created:			  05 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	Net_DIME
PORTVERSION=	0.3
CATEGORIES=	net pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The PEAR::Net_DIME class implements DIME encoding

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		DIME.php
TESTS=		dime_message_test.php dime_record_test.php
_TESTSDIR=	test

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
