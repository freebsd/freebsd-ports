# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	dispatcher
PORTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Dispatcher
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Dispatcher

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librazorback_api.so:security/razorback-api \
		libjson-c.so:devel/json-c \
		libmemcached.so:databases/libmemcached \
		libcli.so:devel/libcli

USES=		autoreconf libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_MYSQL=	yes
USE_RC_SUBR=	dispatcher dispatcher_safed
SUB_FILES=	pkg-message
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS?=		razorback
GROUPS?=	razorback

OPTIONS_DEFINE=	DEBUG ASSERT ACTIVEMQ

ASSERT_DESC=	Enable Asserts
ASSERT_CONFIGURE_ENABLE=	assert
ACTIVEMQ_DESC=	ActiveMQ runs locally
DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MACTIVEMQ}
RUN_DEPENDS=	${LOCALBASE}/etc/rc.d/activemq:net/activemq
SUB_LIST=	ACTIVEMQ="activemq " ACTIVEMQ_LOC="local" \
		ACTIVEMQ_LOCATION="in the ActiveMQ configuration directory:" \
		ACTIVEMQ_CONFIG="${LOCALBASE}/etc/activemq/"
.else
SUB_LIST=	ACTIVEMQ="" ACTIVEMQ_LOC="remote" \
		ACTIVEMQ_LOCATION="on the remote ActiveMQ host." \
		ACTIVEMQ_CONFIG=""
.endif

.include <bsd.port.mk>
