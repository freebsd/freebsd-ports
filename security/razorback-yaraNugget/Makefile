# New ports collection makefile for:	razorback-yaraNugget
# Date created:				2011/06/8
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$
#

PORTNAME=	yaraNugget
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Yara Detection

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	razorback_api:${PORTSDIR}/security/razorback-api \
		pcre:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget
RUN_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget

OPTIONS_DEFINE=	DEBUG ASSERT
ASSERT_DESC=	Enable Asserts

.include <bsd.port.options.mk>

RB_LIBDIR?=	${PREFIX}/lib/razorback
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	${RB_LIBDIR}

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MASSERT}
CONFIGURE_ARGS+=--enable-assert
.endif

post-install:
	${LN} -sf ${RB_LIBDIR}/yaraNugget.so.2 ${RB_LIBDIR}/yaraNugget.so.2.0.0
	@if [ ! -f ${PREFIX}/etc/razorback/yara.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/yara.conf.sample ${PREFIX}/etc/razorback/yara.conf ; \
	fi

.include <bsd.port.mk>
