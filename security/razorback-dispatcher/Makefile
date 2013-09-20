# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	dispatcher
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Dispatcher
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Dispatcher

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	razorback_api:${PORTSDIR}/security/razorback-api \
		memcached:${PORTSDIR}/databases/libmemcached \
		cli:${PORTSDIR}/devel/libcli

OPTIONS_DEFINE=	DEBUG ASSERT ACTIVEMQ
ASSERT_DESC=	Enable Asserts
ACTIVEMQ_DESC=	ActiveMQ runs locally

USES=	pathfix pkgconfig
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_MYSQL=	yes
USE_RC_SUBR=	dispatcher dispatcher_safed
SUB_FILES=	pkg-message
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS?=		razorback
GROUPS?=	razorback

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MASSERT}
CONFIGURE_ARGS+=--enable-assert
.endif

.if ${PORT_OPTIONS:MACTIVEMQ}
RUN_DEPENDS=	${LOCALBASE}/etc/rc.d/activemq:${PORTSDIR}/net/activemq
SUB_LIST=	ACTIVEMQ="activemq " ACTIVEMQ_LOC="local" \
		ACTIVEMQ_LOCATION="in the ActiveMQ configuration directory:" \
		ACTIVEMQ_CONFIG="${LOCALBASE}/etc/activemq/"
.else
SUB_LIST=	ACTIVEMQ="" ACTIVEMQ_LOC="remote" \
		ACTIVEMQ_LOCATION="on the remote ActiveMQ host." \
		ACTIVEMQ_CONFIG=""
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/razorback/dispatcher.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/dispatcher.conf.sample ${PREFIX}/etc/razorback/dispatcher.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
