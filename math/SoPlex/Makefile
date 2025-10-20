PORTNAME=	SoPlex
DISTVERSION=	7.1.1.0
PORTREVISION=	5
CATEGORIES=	math science
MASTER_SITES=	http://soplex.zib.de/download/release/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimization package for solving linear programming problems (LPs)
WWW=		https://soplex.zib.de

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libgmp.so:math/gmp

USES=		cmake compiler:c++14-lang tar:tgz
USE_LDCONFIG=	yes

TEST_TARGET=	test

PLIST_SUB=	SHL4=${DISTVERSION:R:R} SHL2=${DISTVERSION}

OPTIONS_DEFINE=		MPFR

MPFR_DESC=		Use MPFR for multiple-precision floating-point numbers
MPFR_CMAKE_BOOL=	MPFR
MPFR_LIB_DEPENDS=	libmpfr.so:math/mpfr

.include <bsd.port.mk>
