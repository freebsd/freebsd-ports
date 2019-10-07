# Created by: Hans Petter Selasky <hselasky@freebsd.org>
# $FreeBSD$

PORTNAME=	rshim-user-space
PORTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Userspace daemon for the Mellanox BlueField SoC

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libpci.so:devel/libpci \
		libpciaccess.so:devel/libpciaccess

USES=		gmake tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	Mellanox
GH_PROJECT=	rshim-user-space
GH_TAGNAME=	v1.0-alpha.1

OPTIONS_DEFINE=	DEBUG
OPTIONS_DEFAULT=

DEBUG_DESC=	Build with debugging support
DEBUG_MAKE_ARGS=HAVE_DEBUG=YES

PLIST_FILES=	sbin/bfrshim

MAKE_ARGS+=	CC="${CC}" \
		PREFIX="${PREFIX}" \
		LOCALBASE="${LOCALBASE}"

MAKEFILE=	Makefile.freebsd

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD || ${OSVERSION} < 1201500 || !exists(/usr/lib/libcuse.so)
IGNORE=		not supported on this operating system combination
.endif

.include <bsd.port.mk>
