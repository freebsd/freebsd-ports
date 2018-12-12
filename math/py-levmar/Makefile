# $FreeBSD$

# levmar library (math/levmar) is bundled

PORTNAME=	levmar
DISTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Binding to levmar library (Levenberg-Marquardt optimization algorithm)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|ö|o|' ${WRKSRC}/AUTHORS # breaks because of non-ascii chars

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_${PORTNAME}.so

do-test:
	@cd ${WRKSRC}/levmar/tests && ${PYTHON_CMD} -m pytest --pyargs levmar

.include <bsd.port.mk>
