# Ports collection makefile for:  pear-Net_UserAgent_Mobile
# Date created:			  06 June 2005
# Whom:				  Shinsuke Matsui (<smatsui@karashi.org>)
#
# $FreeBSD$
#

PORTNAME=	Net_UserAgent_Mobile
PORTVERSION=	0.23.0
CATEGORIES=	net www pear

MAINTAINER=	smatsui@karashi.org
COMMENT=	PEAR class that parses HTTP mobile user agent string

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net/UserAgent
FILES=		Mobile.php Mobile/AirHPhone.php Mobile/Common.php \
		Mobile/Display.php Mobile/DoCoMo.php Mobile/DoCoMoDisplayMap.php \
		Mobile/EZweb.php Mobile/Vodafone.php Mobile/NonMobile.php \
		Mobile/Request.php
TESTS=		00-compile.phpt 01-request.phpt 02-docomo.phpt \
		03-jphone.phpt 04-ezweb.phpt 05-display.phpt \
		06-nonmobile.phpt 07-airhphone.phpt 08-display-xmlmap.phpt \
		DoCoMoMap.xml

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
