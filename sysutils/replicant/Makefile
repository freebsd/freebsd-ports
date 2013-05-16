# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	replicant
PORTVERSION=	0.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://hyperdex.org/src/

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Replicant is a tool for creating replicated state machines

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libpo6.pc:${PORTSDIR}/devel/libpo6
LIB_DEPENDS=	busybee:${PORTSDIR}/devel/busybee \
		e:${PORTSDIR}/devel/libe \
		glog:${PORTSDIR}/devel/glog \
		leveldb:${PORTSDIR}/databases/leveldb \
		popt:${PORTSDIR}/devel/popt

ONLY_FOR_ARCHS=	amd64
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USES=		pathfix pkgconfig

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 90014 || !exists(clang++)
# newer GCC versions than 4.6 do not work; clang 3.1 seems fine;
# bug report to upstream at: <https://github.com/rescrv/po6/issues/5>
USE_GCC=	4.6
.else
CC=		clang
CXX=		clang++
CPP=		clang-cpp
.endif

.include <bsd.port.post.mk>
