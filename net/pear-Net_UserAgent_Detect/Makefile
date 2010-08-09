# Ports collection makefile for:  pear-Net_UserAgent_Detect
# Date created:			  04 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_UserAgent_Detect
PORTVERSION=	2.5.2
CATEGORIES=	net www pear

MAINTAINER=	joehorn@gmail.com
COMMENT=	PEAR class that determines the Web browser, version, and platform

LICENSE=	BSD

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Detect/APC.php UserAgent/Detect.php
TESTS=		example.php

post-extract:
	@${MKDIR} ${WRKSRC}/UserAgent
	@${MV} ${WRKSRC}/Detect.php ${WRKSRC}/UserAgent
	@${REINPLACE_CMD} -e "s|../Detect.php|${CATEGORY}/${FILES}|" \
		${WRKSRC}/tests/${TESTS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
