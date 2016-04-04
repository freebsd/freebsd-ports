# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-utils
PORTVERSION=	0.7
CATEGORIES=	sysutils
MASTER_SITES=	https://nuxi.nl/distfiles/cloudabi-utils/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Utilities for running CloudABI programs

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libyaml.so:textproc/libyaml

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	CloudABI has not yet been ported to other architectures

USES=		cmake compiler:c11 pkgconfig tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=man

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000100
IGNORE=		CloudABI will never support this version of FreeBSD
.endif

.include <bsd.port.post.mk>
