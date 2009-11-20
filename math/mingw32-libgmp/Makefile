# New ports collection makefile for:   mingw32-libgmp4
# Date created:        28 April 2008
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	libgmp4
PORTVERSION=	4.3.1
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gmp
PKGNAMEPREFIX=	mingw32-
DISTNAME=	gmp-${PORTVERSION}

MAINTAINER=	timbob@bigpond.com
COMMENT=	Library for arbitrary precision arithmetic (MinGW32)

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:${PORTSDIR}/devel/mingw32-bin-msvcrt

GNU_CONFIGURE=	yes
CC=		${PKGNAMEPREFIX}gcc
CXX=		${PKGNAMEPREFIX}c++
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split" \
		PREFIX="${PREFIX}/${PKGNAMEPREFIX:S/-$//}"
CONFIGURE_ARGS=	--enable-cxx --host=${PKGNAMEPREFIX:S/-$//} \
		--includedir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include \
		--exec_prefix=${PREFIX}/${PKGNAMEPREFIX:S/-$//} \
		--datadir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/share \
		--libdir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/lib
CONFIGURE_TARGET=

INFO=		gmp
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

post-extract:
	@${RM} -f ${WRKSRC}/doc/gmp.info*

pre-install:
	${MKDIR} ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info

.include <bsd.port.mk>
