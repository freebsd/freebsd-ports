# Created by: Hans Petter Selasky <hselasky@freebsd.org>
# $FreeBSD$

PORTNAME=	rshim-user-space
DISTVERSIONPREFIX=	rshim-
DISTVERSION=		2.0.5-10

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Userspace daemon for the Mellanox BlueField SoC

LICENSE=	BSD3CLAUSE

CATEGORIES=	sysutils

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libpci.so:devel/libpci \
		libpciaccess.so:devel/libpciaccess

USES=		autoreconf compiler:c11 localbase gmake pkgconfig tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	Mellanox

GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD || ${OSVERSION} < 1201500 || !exists(/usr/lib/libcuse.so)
IGNORE=		not supported on this operating system combination
.endif

.include <bsd.port.mk>
