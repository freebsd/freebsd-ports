# Created by: Tom Judge <tom@tomjudge.com>

PORTNAME=	clamavNugget
PORTVERSION=	0.5.0
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - ClamAV Detection

DEPRECATED=	Abandonware, last release in 2012 and listed as alpha quality by upstream
EXPIRATION_DATE=2022-03-31

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librazorback_api.so:security/razorback-api \
		libjson-c.so:devel/json-c \
		libclamav.so:security/clamav
BUILD_DEPENDS=	razorback-masterNugget>=0.5.0:security/razorback-masterNugget
RUN_DEPENDS=	razorback-masterNugget>=0.5.0:security/razorback-masterNugget

USES=		autoreconf libtool pkgconfig
RB_LIBDIR?=	${PREFIX}/lib/razorback
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${RB_LIBDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG ASSERT

ASSERT_DESC=	Enable Asserts
ASSERT_CONFIGURE_ENABLE=	assert
DEBUG_CONFIGURE_ENABLE=	debug

post-install:
	${LN} -sf ${RB_LIBDIR}/clamavNugget.so.2 \
		${STAGEDIR}${RB_LIBDIR}/clamavNugget.so.2.0.0

.include <bsd.port.mk>
