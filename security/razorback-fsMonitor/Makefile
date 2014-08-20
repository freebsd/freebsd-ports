# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	fsMonitor
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - File System Monitor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librazorback_api.so:${PORTSDIR}/security/razorback-api \
		libjson-c.so:${PORTSDIR}/devel/json-c \
		libfam.so:${PORTSDIR}/devel/fam

USES=		libtool pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG ASSERT

ASSERT_CONFIGURE_ENABLE=	assert
DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.mk>
