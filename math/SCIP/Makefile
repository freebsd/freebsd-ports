# Created by: Yuri Victorovich <yuri@FreeBSD.org>

PORTNAME=	SCIP
DISTVERSION=	7.0.3
PORTREVISION=	2
CATEGORIES=	math science
MASTER_SITES=	https://www.scipopt.org/download/release/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for mixed integer, mixed integer nonlinear programming

LICENSE=	ZIB
LICENSE_NAME=	ZIB ACADEMIC LICENSE
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

EXTRACT_DEPENDS=	gtar:archivers/gtar
LIB_DEPENDS=	libgmp.so:math/gmp \
		libsoplex.so:math/SoPlex

USES=		compiler:c11 cmake readline tar:tgz
EXTRACT_CMD=	gtar
USE_LDCONFIG=	yes

CMAKE_OFF=	PAPILO

CXXFLAGS+=	-I${LOCALBASE}/include/soplex

OPTIONS_DEFINE=		IPOPT ZIMPL
OPTIONS_DEFAULT=	IPOPT

IPOPT_DESC=		Non-linear optimization support via Ipopt
IPOPT_USES=		fortran pkgconfig
IPOPT_CMAKE_BOOL=	IPOPT
IPOPT_LIB_DEPENDS=	libblas.so:math/blas \
			libipopt.so:math/ipopt \
			liblapack.so:math/lapack

ZIMPL_DESC=		Build with Zimpl to translate LP models
ZIMPL_CMAKE_BOOL=	ZIMPL
ZIMPL_LIB_DEPENDS=	libzimpl.so:math/zimpl
ZIMPL_BROKEN=		see https://github.com/scipopt/scip/issues/4

.include <bsd.port.mk>
