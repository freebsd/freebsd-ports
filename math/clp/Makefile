# New ports collection makefile for:   Clp
# Date created:        22 July 2007
# Whom:                Robin Schilham
#
# $FreeBSD$
#

PORTNAME=	Clp
PORTVERSION=	1.12.1
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/Clp/ \
		http://www.mavetju.org/download/adopted/
EXTRACT_SUFX=	.tgz

MAINTAINER=	co9co9@gmail.com
COMMENT=	Linear Programming Solver

LIB_DEPENDS=	lapack.4:${PORTSDIR}/math/lapack

USE_FORTRAN=	yes
CXXFLAGS+=	-ffast-math -fomit-frame-pointer

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	${MAKE_ENV}
CONFIGURE_ARGS=	--with-blas="-L${LOCALBASE}/lib -lblas"		\
		--with-lapack="-L${LOCALBASE}/lib -llapack"

regression-test: build
	(cd ${WRKSRC}/Clp && ${MAKE} unitTest )

.include <bsd.port.mk>
