# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	yaraNugget
PORTVERSION=	0.5.0
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Yara Detection

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librazorback_api.so:security/razorback-api \
		libjson-c.so:devel/json-c \
		libpcre.so:devel/pcre
BUILD_DEPENDS=	razorback-masterNugget>=0.5.0:security/razorback-masterNugget
RUN_DEPENDS=	razorback-masterNugget>=0.5.0:security/razorback-masterNugget

RB_LIBDIR?=	${PREFIX}/lib/razorback
GNU_CONFIGURE=	yes
USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	${RB_LIBDIR}

OPTIONS_DEFINE=	DEBUG ASSERT

ASSERT_DESC=	Enable Asserts
ASSERT_CONFIGURE_ENABLE=	assert
DEBUG_CONFIGURE_ENABLE=	debug

post-patch:
	@${REINPLACE_CMD} 's|-Werror||' ${WRKSRC}/libyara/configure.ac

post-install:
	${LN} -sf ${RB_LIBDIR}/yaraNugget.so.2 \
		${STAGEDIR}${RB_LIBDIR}/yaraNugget.so.2.0.0

.include <bsd.port.mk>
