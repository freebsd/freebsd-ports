PORTNAME=	SCIP
DISTVERSION=	9.2.4
CATEGORIES=	math science
MASTER_SITES=	https://www.scipopt.org/download/release/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for mixed integer, mixed integer nonlinear programming
WWW=		https://www.scipopt.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

EXTRACT_DEPENDS=	gtar:archivers/gtar
LIB_DEPENDS=	libgmp.so:math/gmp \
		libsoplex.so:math/SoPlex

USES=		compiler:c11 cmake readline tar:tgz
EXTRACT_CMD=	gtar
USE_LDCONFIG=	yes

CMAKE_OFF=	PAPILO

CXXFLAGS+=	-I${LOCALBASE}/include/soplex

TEST_TARGET=	test # 2 tests fail, see https://github.com/scipopt/scip/issues/78

OPTIONS_DEFINE=		IPOPT ZIMPL
OPTIONS_DEFAULT=	IPOPT

IPOPT_DESC=		Non-linear optimization support via Ipopt
IPOPT_USES=		fortran pkgconfig
IPOPT_CMAKE_BOOL=	IPOPT
IPOPT_LIB_DEPENDS=	libipopt.so:math/ipopt

ZIMPL_DESC=		Build with Zimpl to translate LP models
ZIMPL_CMAKE_BOOL=	ZIMPL
ZIMPL_LIB_DEPENDS=	libzimpl.so:math/zimpl
ZIMPL_BROKEN=		see https://github.com/scipopt/scip/issues/4

INSTALL_CONFLICTS=	scipoptsuite

.include <bsd.port.mk>
