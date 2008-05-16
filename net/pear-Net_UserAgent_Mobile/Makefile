# Ports collection makefile for:  pear-Net_UserAgent_Mobile
# Date created:			  06 June 2005
# Whom:				  Shinsuke Matsui (<smatsui@karashi.org>)
#
# $FreeBSD$
#

PORTNAME=	Net_UserAgent_Mobile
PORTVERSION=	1.0.0
CATEGORIES=	net www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}RC1

MAINTAINER=	smatsui@karashi.org
COMMENT=	PEAR class that parses HTTP mobile user agent string

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	pcre

CATEGORY=	Net/UserAgent
FILES=		Mobile.php Mobile/Common.php \
		Mobile/Display.php Mobile/DoCoMo.php \
		Mobile/EZweb.php Mobile/NonMobile.php \
		Mobile/SoftBank.php Mobile/Willcom.php \
		Mobile/DoCoMo/ScreenInfo.php
TESTS=		AllTests.php MobileTestCase.php prepare.php \
		Mobile/AllTests.php Mobile/DoCoMoTestCase.php \
		Mobile/EZwebTestCase.php Mobile/NonMobileTestCase.php \
		Mobile/SoftBankTestCase.php \
		Mobile/WillcomTestCase.php \
		Mobile/DoCoMoTestCase/docomo-screen.xml

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
