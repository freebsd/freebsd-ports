# Created by: Robin Schilham
# $FreeBSD$

PORTNAME=	Clp
PORTVERSION=	1.16.10
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/${PORTNAME}/ \
		http://www.mavetju.org/download/adopted/

MAINTAINER=	co9co9@gmail.com
COMMENT=	Linear Programming Solver

LICENSE=	EPL

USES=		blaslapack compiler:c++11-lang fortran libtool pathfix tar:tgz
CXXFLAGS+=	-ffast-math

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	unitTest
TEST_WRKSRC=	${WRKSRC}/${PORTNAME}

CONFIGURE_ARGS=	--with-lapack-lib="${LAPACKLIB} -L${LOCALBASE}/lib" \
		--with-blas-lib="${BLASLIB} -L${LOCALBASE}/lib" \
		--datadir=${DATADIR}

OPTIONS_DEFINE=	DEBUG DOCS
PORTDOCS=	*

DEBUG_CXXFLAGS=	-fomit-frame-pointer

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
