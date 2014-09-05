# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	yaraNugget
PORTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Yara Detection

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librazorback_api.so:${PORTSDIR}/security/razorback-api \
		libjson-c.so:${PORTSDIR}/devel/json-c \
		libpcre.so:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget
RUN_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget

RB_LIBDIR?=	${PREFIX}/lib/razorback
GNU_CONFIGURE=	yes
USES=		libtool pkgconfig
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	${RB_LIBDIR}

OPTIONS_DEFINE=	DEBUG ASSERT

ASSERT_DESC=	Enable Asserts
ASSERT_CONFIGURE_ENABLE=	assert
DEBUG_CONFIGURE_ENABLE=	debug

post-patch:
	@${REINPLACE_CMD} '/CWARNINGS/ s|-Werror||' ${WRKSRC}/configure

post-install:
	${LN} -sf ${RB_LIBDIR}/yaraNugget.so.2 \
		${STAGEDIR}${RB_LIBDIR}/yaraNugget.so.2.0.0

.include <bsd.port.mk>
