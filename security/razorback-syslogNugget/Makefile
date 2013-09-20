# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	syslogNugget
PORTVERSION=	0.5.0
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Syslog Output

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	razorback_api:${PORTSDIR}/security/razorback-api
BUILD_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget
RUN_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget

OPTIONS_DEFINE=	DEBUG ASSERT
ASSERT_DESC=	Enable Asserts

USES=		pkgconfig
RB_LIBDIR?=	${PREFIX}/lib/razorback
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	${RB_LIBDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MASSERT}
CONFIGURE_ARGS+=--enable-assert
.endif

post-install:
	${LN} -sf ${RB_LIBDIR}/syslogNugget.so.2 ${RB_LIBDIR}/syslogNugget.so.2.0.0
	@if [ ! -f ${PREFIX}/etc/razorback/syslog.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/syslog.conf.sample ${PREFIX}/etc/razorback/syslog.conf ; \
	fi

.include <bsd.port.mk>
