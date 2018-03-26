# $FreeBSD$

PORTNAME=	cvxopt
DISTVERSION=	1.1.9
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python software for convex optimization

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libumfpack.so:math/suitesparse

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

CFLAGS+=	-I${LOCALBASE}/include/suitesparse

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cvxopt/*.so
	# workaround: empty directory is installed: https://github.com/cvxopt/cvxopt/issues/111
	@${RMDIR} ${STAGEDIR}${PREFIX}/cvxopt
	@${REINPLACE_CMD} -e 's|${PREFIX}/cvxopt||' ${_PYTHONPKGLIST}

.include <bsd.port.mk>
