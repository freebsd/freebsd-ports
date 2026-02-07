PORTNAME=	xformers
DISTVERSION=	0.0.25
PORTREVISION=	2
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Transformers building blocks, supporting a composable construction
WWW=		https://facebookresearch.github.io/xformers/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.1:misc/py-pytorch@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytorch>=2.1:misc/py-pytorch@${PY_FLAVOR} \
		${PYNUMPY}

USES=		compiler:c++17-lang localbase python
USE_PYTHON=	distutils autoplist pytest # tests fail, see https://github.com/facebookresearch/xformers/issues/1003

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/xformers/_C.so

.include <bsd.port.mk>
