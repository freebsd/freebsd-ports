# $FreeBSD$

PORTNAME=	cvxopt
DISTVERSION=	1.2.1
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

.include <bsd.port.mk>
