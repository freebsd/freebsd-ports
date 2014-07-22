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

LIB_DEPENDS=	libconfig.so:${PORTSDIR}/devel/libconfig \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libjson.so:${PORTSDIR}/devel/json-c

OPTIONS_DEFINE=	DEBUG ASSERT CNC_DEBUG STOMP_DEBUG

CNC_DEBUG_DESC=		Enable Command and Control Debug
STOMP_DEBUG_DESC=	Enable STOMP Debug

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BROKEN_sparc64=	Does not compile on sparc64

.include <bsd.port.options.mk>

.if !empty(PORT_OPTIONS:MDEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.if !empty(PORT_OPTIONS:MASSERT)
CONFIGURE_ARGS+=--enable-assert
.endif

.if !empty(PORT_OPTIONS:MCNC_DEBUG)
CONFIGURE_ARGS+=--enable-cnc-debug
.endif

.if !empty(PORT_OPTIONS:MSTOMP_DEBUG)
CONFIGURE_ARGS+=--enable-stomp-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/-Werror//g" \
			  ${WRKSRC}/configure

.include <bsd.port.mk>
