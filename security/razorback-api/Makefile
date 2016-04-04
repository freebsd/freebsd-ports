# $FreeBSD$

PORTNAME=	api
PORTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/API
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Framework for an intelligence driven security solution - API

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libuuid.so:misc/e2fsprogs-libuuid \
		libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c

OPTIONS_DEFINE=	DEBUG ASSERT CNC_DEBUG STOMP_DEBUG

CNC_DEBUG_DESC=		Enable Command and Control Debug
STOMP_DEBUG_DESC=	Enable STOMP Debug

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BROKEN_sparc64=	Does not compile on sparc64

DEBUG_CONFIGURE_ENABLE=		debug
ASSERT_CONFIGURE_ENABLE=	assert
CNC_DEBUG_CONFIGURE_ENABLE=	cnc-debug
STOMP_DEBUG_CONFIGURE_ENABLE=	stomp-debug

.include <bsd.port.mk>
