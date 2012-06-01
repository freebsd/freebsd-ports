# New ports collection makefile for:	razorback-fsMonitor
# Date created:				2011/06/8
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$
#

PORTNAME=	fsMonitor
PORTVERSION=	0.5.0
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - File System Monitor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	razorback_api.2:${PORTSDIR}/security/razorback-api \
		fam.0:${PORTSDIR}/devel/fam

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
	@if [ ! -f ${PREFIX}/etc/razorback/fsMonitor.conf ]; then \
		${CP} -p ${PREFIX}/etc/razorback/fsMonitor.conf.sample ${PREFIX}/etc/razorback/fsMonitor.conf ; \
	fi

.include <bsd.port.mk>
