# $FreeBSD$

PORTNAME=	blaze
DISTVERSION=	3.3-430
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

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

USES=		cmake:outsource compiler:c++14-lang fortran localbase:ldflags
NO_ARCH=	yes

BB_ACCOUNT=	${PORTNAME}-lib
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	ea158fdf70ef

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

.include <bsd.port.mk>
