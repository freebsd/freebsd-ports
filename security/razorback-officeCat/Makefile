# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	officeCat
PORTVERSION=	0.5.0
PORTREVISION=	1
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

USES=		pkgconfig

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	only supported under i386 due to wine requirements

OPTIONS_DEFINE=	DEBUG ASSERT
ASSERT_DESC=	Enable Asserts

NO_STAGE=	yes
.include <bsd.port.options.mk>

RB_LIBDIR?=	${PREFIX}/lib/razorback
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool autoconf
USE_LDCONFIG=	${RB_LIBDIR}

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MASSERT}
CONFIGURE_ARGS+=--enable-assert
.endif

post-install:
	${LN} -sf ${RB_LIBDIR}/officeCat.so.2 ${RB_LIBDIR}/officeCat.so.2.0.0
	@if [ ! -f ${PREFIX}/etc/razorback/officecat.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/officecat.conf.sample ${PREFIX}/etc/razorback/officecat.conf ; \
	fi

.include <bsd.port.mk>
