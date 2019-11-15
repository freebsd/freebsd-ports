# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	dispatcher
PORTVERSION=	0.5.0
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Dispatcher
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Dispatcher

BROKEN=		uses deprecated libssh API

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librazorback_api.so:security/razorback-api \
		libjson-c.so:devel/json-c \
		libmemcached.so:databases/libmemcached \
		libcli.so:devel/libcli

USES=		autoreconf libtool mysql pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_RC_SUBR=	dispatcher dispatcher_safed
SUB_FILES=	pkg-message
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS?=		razorback
GROUPS?=	razorback

OPTIONS_DEFINE=	DEBUG ASSERT ACTIVEMQ

ACTIVEMQ_DESC=	ActiveMQ runs locally
ASSERT_DESC=	Enable Asserts

ACTIVEMQ_RUN_DEPENDS=	${LOCALBASE}/etc/rc.d/activemq:net/activemq
ACTIVEMQ_SUB_LIST=	ACTIVEMQ="activemq " ACTIVEMQ_LOC="local" \
			ACTIVEMQ_LOCATION="in the ActiveMQ configuration directory:" \
			ACTIVEMQ_CONFIG="${LOCALBASE}/etc/activemq/"
ACTIVEMQ_SUB_LIST_OFF=	ACTIVEMQ="" ACTIVEMQ_LOC="remote" \
			ACTIVEMQ_LOCATION="on the remote ActiveMQ host." \
			ACTIVEMQ_CONFIG=""
ASSERT_CONFIGURE_ENABLE=	assert
DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.mk>
