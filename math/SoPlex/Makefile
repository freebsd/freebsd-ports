PORTNAME=	SoPlex
DISTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	http://soplex.zib.de/download/release/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimization package for solving linear programming problems (LPs)

LICENSE=	ZIB
LICENSE_NAME=	ZIB ACADEMIC LICENSE
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	no-dist-mirror no-pkg-mirror no-auto-accept

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libgmp.so:math/gmp

USES=		cmake compiler:c++14-lang tar:tgz
USE_LDCONFIG=	yes

TEST_TARGET=	test

PLIST_SUB=	SHL4=${DISTVERSION}.0 SHL2=${DISTVERSION:R}

OPTIONS_DEFINE=		MPFR

MPFR_DESC=		Use MPFR for multiple-precision floating-point numbers
MPFR_CMAKE_BOOL=	MPFR
MPFR_LIB_DEPENDS=	libmpfr.so:math/mpfr

.include <bsd.port.mk>
