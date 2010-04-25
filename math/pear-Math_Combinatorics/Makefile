# Ports collection makefile for:  pear-Math_Combinatorics
# Date created:			  20 May 2007
# Whom:				  Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Math_Combinatorics
PORTVERSION=	1.0.0
PORTEPOCH=	1
CATEGORIES=	math pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A package that produces combinations and permutations

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Math
FILES=		Combinatorics.php
IGNORE_WITH_PHP=4

TESTS=		test_1.phpt test_2.phpt test_3.phpt test_4.phpt \
		test_5.phpt test_6.phpt

EXAMPLES=	example.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
