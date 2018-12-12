# $FreeBSD$

PORTNAME=	pcmsolver
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API for the Polarizable Continuum Model

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: SphericalDiffuse.cpp:182: invalid initialization of non-const reference

LIB_DEPENDS=	libflang.so:devel/flang # USES=fortran:clang breaks in configure: can't find libs directory

USES=		cmake:outsource,noninja python
USE_GITHUB=	yes
GH_ACCOUNT=	PCMSolver
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|"-O3 |"$${CMAKE_C_FLAGS} |' \
		${WRKSRC}/cmake/custom/compilers/*.cmake

.include <bsd.port.mk>
