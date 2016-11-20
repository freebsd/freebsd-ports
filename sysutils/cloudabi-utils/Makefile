# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-utils
PORTVERSION=	0.18
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Utilities for running CloudABI programs

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/cloudabi_types.h:devel/cloudabi
LIB_DEPENDS=	libyaml.so:textproc/libyaml

USE_GITHUB=	yes
GH_ACCOUNT=	NuxiNL

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 i386
ONLY_FOR_ARCHS_REASON=	CloudABI has not yet been ported to other architectures

USES=		cmake compiler:c11 pkgconfig tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=man
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1001511
IGNORE=		requires a recent implementation of Capsicum
.endif

.include <bsd.port.post.mk>
