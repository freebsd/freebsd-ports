# Created by: Robin Schilham
# $FreeBSD$

PORTNAME=	Clp
PORTVERSION=	1.12.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/Clp/ \
		http://www.mavetju.org/download/adopted/
EXTRACT_SUFX=	.tgz

MAINTAINER=	co9co9@gmail.com
COMMENT=	Linear Programming Solver

LIB_DEPENDS=	lapack.4:${PORTSDIR}/math/lapack

USES=		fortran
CXXFLAGS+=	-ffast-math -fomit-frame-pointer

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	${MAKE_ENV}
CONFIGURE_ARGS=	--with-blas="-L${LOCALBASE}/lib -lblas"		\
		--with-lapack="-L${LOCALBASE}/lib -llapack"

regression-test: build
	(cd ${WRKSRC}/Clp && ${MAKE} unitTest )

NO_STAGE=	yes
.include <bsd.port.mk>
