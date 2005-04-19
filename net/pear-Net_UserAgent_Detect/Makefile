# Ports collection makefile for:  pear-Net_UserAgent_Detect
# Date created:			  04 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_UserAgent_Detect
PORTVERSION=	2.1.0
CATEGORIES=	net www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class that detects web browser, version and platform

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

CATEGORY=	Net
FILES=		UserAgent/Detect.php
TESTS=		example.php

post-extract:
	@${MKDIR} ${WRKSRC}/UserAgent
	@${MV} ${WRKSRC}/Detect.php ${WRKSRC}/UserAgent
	@${REINPLACE_CMD} -e "s|../Detect.php|${CATEGORY}/${FILES}|" \
		${WRKSRC}/tests/${TESTS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
