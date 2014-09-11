# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	officeCat
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - OfficeCat Detection

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librazorback_api.so:${PORTSDIR}/security/razorback-api \
		libjson-c.so:${PORTSDIR}/devel/json-c
BUILD_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget \
		wine:${PORTSDIR}/emulators/wine
RUN_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget \
		wine:${PORTSDIR}/emulators/wine

USES=		pkgconfig libtool

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	only supported under i386 due to wine requirements

OPTIONS_DEFINE=	DEBUG ASSERT
ASSERT_DESC=	Enable Asserts

RB_LIBDIR?=	${PREFIX}/lib/razorback
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	${RB_LIBDIR}
INSTALL_TARGET=	install-strip

DEBUG_CONFIGURE_ENABLE=	debug
ASSERT_CONFIGURE_ENABLE=assert

.include <bsd.port.mk>
