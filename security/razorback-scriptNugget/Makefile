# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	scriptNugget
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Scripting Interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	razorback_api:${PORTSDIR}/security/razorback-api
BUILD_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget
RUN_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget \
		rubygem-razorback-scriptNugget>=0.5.0:${PORTSDIR}/security/rubygem-razorback-scriptNugget

OPTIONS_DEFINE=	DEBUG ASSERT
ASSERT_DESC=	Enable Asserts

RB_LIBDIR?=	${PREFIX}/lib/razorback
USES=		pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-ruby
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
	${LN} -sf ${RB_LIBDIR}/scriptNugget.so.2 ${RB_LIBDIR}/scriptNugget.so.2.0.0
	@if [ ! -f ${PREFIX}/etc/razorback/scriptNugget.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/scriptNugget.conf.sample ${PREFIX}/etc/razorback/scriptNugget.conf ; \
	fi

.include <bsd.port.mk>
