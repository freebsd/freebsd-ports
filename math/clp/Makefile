# Created by: Robin Schilham
# $FreeBSD$

PORTNAME=	Clp
DISTVERSION=	1.17.3
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/${PORTNAME}/ \
		http://www.mavetju.org/download/adopted/
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	co9co9@gmail.com
COMMENT=	Linear Programming Solver

LICENSE=	EPL

USES=		blaslapack compiler:c++11-lang fortran libtool pathfix tar:tgz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-lapack-lib="${LAPACKLIB} -L${LOCALBASE}/lib" \
		--with-blas-lib="${BLASLIB} -L${LOCALBASE}/lib" \
		--datadir=${DATADIR}

TEST_TARGET=	unitTest
TEST_WRKSRC=	${WRKSRC}/${PORTNAME}

OPTIONS_DEFINE=	DEBUG DOCS
PORTDOCS=	*

CXXFLAGS+=	-ffast-math
DEBUG_CXXFLAGS=	-fomit-frame-pointer

.include <bsd.port.mk>
