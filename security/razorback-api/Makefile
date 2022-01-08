PORTNAME=	api
PORTVERSION=	0.5.0
PORTREVISION=	9
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/API
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for an intelligence driven security solution - API

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Abandonware, last release in 2012 and listed as alpha quality by upstream
EXPIRATION_DATE=2022-03-31

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libssh.so:security/libssh \
		libuuid.so:misc/e2fsprogs-libuuid \
		libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c

OPTIONS_DEFINE=	DEBUG ASSERT CNC_DEBUG STOMP_DEBUG

CNC_DEBUG_DESC=		Enable Command and Control Debug
STOMP_DEBUG_DESC=	Enable STOMP Debug

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DEBUG_CONFIGURE_ENABLE=		debug
ASSERT_CONFIGURE_ENABLE=	assert
CNC_DEBUG_CONFIGURE_ENABLE=	cnc-debug
STOMP_DEBUG_CONFIGURE_ENABLE=	stomp-debug

post-patch:
	@${REINPLACE_CMD} -e s/json/json-c/ -e s/-Werror// ${WRKSRC}/configure

.include <bsd.port.mk>
