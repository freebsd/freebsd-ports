# Ports collection makefile for:  pear-Net_MAC
# Date created:			  25 April 2007
# Whom:				  Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net_MAC
PORTVERSION=	0.1.5
CATEGORIES=	net pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class that validates and formats MAC addresses

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		MAC/MAC.php

post-extract:
	@${MKDIR} ${WRKSRC}/MAC
	@${MV} ${WRKSRC}/Net/MAC.php ${WRKSRC}/MAC

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
