# $FreeBSD$

PORTNAME=	blaze
DISTVERSION=	3.4
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ math library for dense and sparse arithmetic

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		openblas>0:math/openblas \
		openmp>0:devel/openmp
RUN_DEPENDS=	boost-libs>0:devel/boost-libs \
		openblas>0:math/openblas \
		openmp>0:devel/openmp

USES=		cmake compiler:c++14-lang fortran localbase:ldflags
NO_ARCH=	yes

BB_ACCOUNT=	${PORTNAME}-lib
BB_PROJECT=	${PORTNAME}

.include <bsd.port.mk>
