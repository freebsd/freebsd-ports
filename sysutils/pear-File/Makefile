# Ports collection makefile for:  pear-File
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	File
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	sysutils www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR common file and directory routines

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		File.php File/CSV.php
TESTS=		parser.php test.csv

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
