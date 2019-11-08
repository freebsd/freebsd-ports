# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	scriptNugget
PORTVERSION=	0.5.0
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Scripting Interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librazorback_api.so:security/razorback-api \
		libjson-c.so:devel/json-c
BUILD_DEPENDS=	razorback-masterNugget>=0.5.0:security/razorback-masterNugget
RUN_DEPENDS=	razorback-masterNugget>=0.5.0:security/razorback-masterNugget \
		rubygem-razorback-scriptNugget>=0.5.0:security/rubygem-razorback-scriptNugget

RB_LIBDIR?=	${PREFIX}/lib/razorback
USES=		autoreconf gnome libtool pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-ruby
USE_LDCONFIG=	${RB_LIBDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG ASSERT

ASSERT_DESC=	Enable Asserts
ASSERT_CONFIGURE_ENABLE=	assert
DEBUG_CONFIGURE_ENABLE=	debug

post-install:
	${LN} -sf ${RB_LIBDIR}/scriptNugget.so.2 \
		${STAGEDIR}${RB_LIBDIR}/scriptNugget.so.2.0.0

.include <bsd.port.mk>
