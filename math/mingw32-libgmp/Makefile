# New ports collection makefile for:   mingw32-libgmp4
# Date created:        28 April 2008
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	libgmp
PORTVERSION=	5.0.5
CATEGORIES=	math devel
MASTER_SITES=	GNU
MASTER_SITE_SUBDIR=	gmp
PKGNAMEPREFIX=	mingw32-
DISTNAME=	gmp-${PORTVERSION}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Library for arbitrary precision arithmetic (MinGW32)

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:${PORTSDIR}/devel/mingw32-bin-msvcrt

USE_BZIP2=	yes
GMP_TARG=	${PKGNAMEPREFIX:S/-$//}
GNU_CONFIGURE=	yes
CC=		${PKGNAMEPREFIX}gcc
CXX=		${PKGNAMEPREFIX}c++
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split" \
		PREFIX="${PREFIX}/${GMP_TARG}"
CONFIGURE_ARGS=	--enable-cxx --host=${GMP_TARG} \
		--includedir=${PREFIX}/${GMP_TARG}/include \
		--exec_prefix=${PREFIX}/${GMP_TARG} \
		--datadir=${PREFIX}/${GMP_TARG}/share \
		--libdir=${PREFIX}/${GMP_TARG}/lib
CONFIGURE_TARGET=

INFO=		gmp
INFO_PATH=	${GMP_TARG}/info

post-extract:
	@${RM} -f ${WRKSRC}/doc/gmp.info*

pre-install:
	${MKDIR} ${PREFIX}/${GMP_TARG}/info

.include <bsd.port.mk>
