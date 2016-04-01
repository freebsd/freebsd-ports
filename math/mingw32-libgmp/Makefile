# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	libgmp
PORTVERSION=	6.0.0
PORTREVISION=	2
CATEGORIES=	math devel
MASTER_SITES=	GNU/gmp
PKGNAMEPREFIX=	mingw32-
DISTNAME=	gmp-${DISTVERSION}a

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Library for arbitrary precision arithmetic (MinGW32)

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:devel/mingw32-bin-msvcrt

WRKSRC=		${WRKDIR}/gmp-${PORTVERSION}

USES=		libtool makeinfo tar:bzip2
GMP_TARG=	${PKGNAMEPREFIX:S/-$//}
GNU_CONFIGURE=	yes
CC=		${PKGNAMEPREFIX}gcc
CXX=		${PKGNAMEPREFIX}c++
CFLAGS+=	-I/usr/include
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split" \
		PREFIX="${PREFIX}/${GMP_TARG}" \
		M4="/usr/bin/m4"
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

.include <bsd.port.mk>
