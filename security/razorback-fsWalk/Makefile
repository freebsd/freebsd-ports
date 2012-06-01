# New ports collection makefile for:	razorback-fsWalk
# Date created:				2011/06/8
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$
#

PORTNAME=	fsWalk
PORTVERSION=	0.5.0
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - File System Walker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	razorback_api.2:${PORTSDIR}/security/razorback-api

OPTIONS_DEFINE=	DEBUG ASSERT

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !empty(PORT_OPTIONS:MDEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.if !empty(PORT_OPTIONS:MASSERT)
CONFIGURE_ARGS+=--enable-assert
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/razorback/fsWalk.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/fsWalk.conf.sample ${PREFIX}/etc/razorback/fsWalk.conf ; \
	fi

.include <bsd.port.mk>
