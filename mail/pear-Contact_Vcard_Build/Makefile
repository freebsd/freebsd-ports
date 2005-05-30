# Ports collection makefile for:  pear-Contact_Vcard_Build
# Date created:			  30 May 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Contact_Vcard_Build
PORTVERSION=	1.1.1
CATEGORIES=	mail www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class to build (create) and fetch vCard 2.1 and 3.0 text blocks

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Contact_Vcard_Build.php
TESTS=		test.php
_TESTSDIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
