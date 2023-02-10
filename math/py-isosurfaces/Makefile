PORTNAME=	isosurfaces
DISTVERSION=	0.1.0
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Construct isolines/isosurfaces over a 2D/3D scalar field
WWW=		https://github.com/jared-hughes/isosurfaces

LICENSE=	MIT

RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PYNUMPY} \
		xdg-open:devel/xdg-utils

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/isoline_demo.py && \
		xdg-open ${TEST_WRKSRC}/demo.svg

.include <bsd.port.mk>
