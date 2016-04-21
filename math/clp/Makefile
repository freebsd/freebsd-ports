# Created by: Robin Schilham
# $FreeBSD$

PORTNAME=	Clp
PORTVERSION=	1.16.8
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/Clp/ \
		http://www.mavetju.org/download/adopted/

MAINTAINER=	co9co9@gmail.com
COMMENT=	Linear Programming Solver

LICENSE=	EPL

BROKEN_powerpc64=	Does not build

USES=		blaslapack fortran libtool tar:tgz pathfix
CXXFLAGS+=	-ffast-math

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	unitTest
TEST_WRKSRC=	${WRKSRC}/Clp

CONFIGURE_ENV+=	${MAKE_ENV}
CONFIGURE_ARGS=	--with-lapack-lib="${LAPACKLIB} -L${LOCALBASE}/lib" \
		--with-blas-lib="${BLASLIB} -L${LOCALBASE}/lib" \
		--datadir=${DATADIR}

OPTIONS_DEFINE=	DEBUG
PORTDOCS=	*

DEBUG_CXXFLAGS=	-fomit-frame-pointer

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
