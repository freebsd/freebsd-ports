# Created by: Loic Pefferkorn <loic-freebsd@loicp.eu>
# $FreeBSD$

PORTNAME=	burp
PORTVERSION?=	2.1.32
CATEGORIES=	sysutils

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	Network backup and restore program

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash \
		${LOCALBASE}/include/yajl/yajl_common.h:devel/yajl
LIB_DEPENDS=	librsync.so:net/librsync2

USES=		autoreconf gmake libtool ncurses pkgconfig ssl
USE_GITHUB=	yes
USE_RC_SUBR=	burp

GH_ACCOUNT=	grke

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR}

INSTALL_TARGET=	install-all

CONFLICTS_INSTALL?=	burp-devel

OPTIONS_DEFINE=		IPV6
IPV6_CONFIGURE_ENABLE=	ipv6

.include <bsd.port.mk>
