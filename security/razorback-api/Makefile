# New ports collection makefile for:	razorback-api
# Date created:				2011/06/8
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$
#

PORTNAME=	api
PORTVERSION=	0.5.0
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/API
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tom@tomjudge.com
COMMENT=	Framework for an intelligence driven security solution - API

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	config.10:${PORTSDIR}/devel/libconfig \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		curl.6:${PORTSDIR}/ftp/curl \
		json.0:${PORTSDIR}/devel/json-c

OPTIONS=	DEBUG "Enable Debug" off \
		ASSERT "Enable Asserts" off \
		CNC_DEBUG "Enable Command and Control Debug" off \
		STOMP_DEBUG "Enable STOMP Debug" off

USE_GNOME=	gnomehack
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.if defined(WITH_ASSERT)
CONFIGURE_ARGS+=--enable-assert
.endif

.if defined(WITH_CNC_DEBUG)
CONFIGURE_ARGS+=--enable-cnc-debug
.endif

.if defined(WITH_STOMP_DEBUG)
CONFIGURE_ARGS+=--enable-stomp-debug
.endif

.if ${CC} == "clang" || ${CXX} == "clang++"
BROKEN=		does not build when compiled with clang
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/razorback/api.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/api.conf.sample ${PREFIX}/etc/razorback/api.conf ; \
	fi
	@if [ ! -f ${PREFIX}/etc/razorback/magic ]; then \
		${CP} -p ${PREFIX}/etc/razorback/magic.sample ${PREFIX}/etc/razorback/magic ; \
	fi

.include <bsd.port.mk>
