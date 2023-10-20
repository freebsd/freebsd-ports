PORTNAME=	libgmp
PORTVERSION=	6.1.0
CATEGORIES=	math devel
MASTER_SITES=	GNU/gmp
PKGNAMEPREFIX=	mingw32-
DISTNAME=	gmp-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for arbitrary precision arithmetic (MinGW32)
WWW=		http://www.swox.com/gmp/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Broken for more than a year
EXPIRATION_DATE=	2023-11-20
BROKEN_FreeBSD_13=	error: '::gets' has not been declared
BROKEN_FreeBSD_14=	error: '::gets' has not been declared

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:devel/${PKGNAMEPREFIX}gcc \
		mingwm10.dll:devel/mingw32-bin-msvcrt

USES=		libtool tar:bzip2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cxx --host=${GMP_TARG} \
		--includedir=${PREFIX}/${GMP_TARG}/include \
		--exec_prefix=${PREFIX}/${GMP_TARG} \
		--datadir=${PREFIX}/${GMP_TARG}/share \
		--libdir=${PREFIX}/${GMP_TARG}/lib
CONFIGURE_ENV=	MAKEINFO="${MAKEINFO} --no-split" \
		PREFIX="${PREFIX}/${GMP_TARG}" \
		M4="/usr/bin/m4"
CONFIGURE_TARGET=

CFLAGS+=	-I/usr/include
SSP_CFLAGS?=	-fstack-protector # XXX -strong isn't supported by GCC < 4.9

CC=		${PKGNAMEPREFIX}gcc
CXX=		${PKGNAMEPREFIX}c++

WRKSRC=		${WRKDIR}/gmp-${PORTVERSION}

GMP_TARG=	${PKGNAMEPREFIX:S/-$//}

INFO=		gmp
INFO_PATH=	${GMP_TARG}/info

.include <bsd.port.mk>
