# $FreeBSD$

PORTNAME=	api
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/API
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Framework for an intelligence driven security solution - API

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	config.10:${PORTSDIR}/devel/libconfig \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		curl:${PORTSDIR}/ftp/curl \
		libjson.so:${PORTSDIR}/devel/json-c

OPTIONS_DEFINE=	DEBUG ASSERT CNC_DEBUG STOMP_DEBUG

CNC_DEBUG_DESC=		Enable Command and Control Debug
STOMP_DEBUG_DESC=	Enable STOMP Debug

USES=	pathfix pkgconfig
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
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

.if ${CC} == "clang" || ${CXX} == "clang++"
BROKEN=		does not build when compiled with clang
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/-Werror//g" \
			  ${WRKSRC}/configure

post-install:
	@if [ ! -f ${PREFIX}/etc/razorback/api.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/api.conf.sample ${PREFIX}/etc/razorback/api.conf ; \
	fi
	@if [ ! -f ${PREFIX}/etc/razorback/magic ]; then \
		${CP} -p ${PREFIX}/etc/razorback/magic.sample ${PREFIX}/etc/razorback/magic ; \
	fi

.include <bsd.port.post.mk>
