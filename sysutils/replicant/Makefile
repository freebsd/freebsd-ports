# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	replicant
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://hyperdex.org/src/

MAINTAINER=	vg@FreeBSD.org
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
# The -D-efines and -include beat the code into shape on GCC 4.7/4.8
# GCC 4.6 from ports and 9.1's base clang are fine,
# upstream bug report at <https://github.com/rescrv/po6/issues/5>
# This hack causes harmless "warning: '__STDC_LIMIT_MACROS' macro redefined"
CPPFLAGS+=	-D__STDC_LIMIT_MACROS -Du_int32_t=uint32_t \
		-include stdint.h -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		pathfix pkgconfig

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900014 || !exists(/usr/bin/clang++)
# No clang++ installed, use GCC from ports:
USE_GCC=	yes
.else
CC=		clang
CXX=		clang++
CPP=		clang-cpp
.endif

.include <bsd.port.post.mk>
