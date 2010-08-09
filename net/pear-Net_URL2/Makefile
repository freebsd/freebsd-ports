# Ports collection makefile for:  pear-Net_URL2
# Date created:			  8 May 2007
# Whom:				  Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net_URL2
PORTVERSION=	0.3.1
CATEGORIES=	net www pear

MAINTAINER=	joehorn@gmail.com
COMMENT=	PEAR Class for parsing and handling URL

LICENSE=	BSD

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		URL2.php
EXAMPLES=	example.php
TESTS=		6470.php
_EXAMPLESDIR=	docs
_TESTSDIR=	docs
IGNORE_WITH_PHP=	4

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
