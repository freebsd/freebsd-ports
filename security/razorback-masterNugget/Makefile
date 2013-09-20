# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	masterNugget
PORTVERSION=	0.5.0
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Master Nugget

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	razorback_api:${PORTSDIR}/security/razorback-api

OPTIONS_DEFINE=	DEBUG ASSERT
ASSERT_DESC=	Enable Asserts

USES=		pkgconfig

NO_STAGE=	yes
.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_RC_SUBR=	masterNugget masterNugget_safed
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS?=		razorback
GROUPS?=	razorback

.if ${OSVERSION} <= 800000
BROKEN=		does not currently build under 7.x
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MASSERT}
CONFIGURE_ARGS+=--enable-assert
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/razorback/master_nugget.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/master_nugget.conf.sample ${PREFIX}/etc/razorback/master_nugget.conf ; \
	fi

.include <bsd.port.mk>
