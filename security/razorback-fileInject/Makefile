# New ports collection makefile for:	razorback-fileInject
# Date created:				2011/06/8
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$
#

PORTNAME=	fileInject
PORTVERSION=	0.5.0
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tom@tomjudge.com
COMMENT=	Framework for an intelligence driven security - File Injector

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	razorback_api.2:${PORTSDIR}/security/razorback-api

OPTIONS=	DEBUG "Enable Debug" off \
		ASSERT "Enable Asserts" off

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.if defined(WITH_ASSERT)
CONFIGURE_ARGS+=--enable-assert
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/razorback/fileInject.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/fileInject.conf.sample ${PREFIX}/etc/razorback/fileInject.conf ; \
	fi

.include <bsd.port.mk>
