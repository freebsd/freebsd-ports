PORTNAME=	docling-metrics-text
DISTVERSION=	0.15.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Text metrics
WWW=		https://github.com/docling-project/docling-metrics

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=2.12:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0:devel/py-scikit-build-core@${PY_FLAVOR} \
		loguru>=2.1.0:devel/loguru
LIB_DEPENDS=	libabsl_strings.so:devel/abseil \
		libre2.so:devel/re2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling-metrics-core>=0.0.1:textproc/py-docling-metrics-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}evaluate>=0.4.3:misc/py-evaluate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.9.1:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=0:devel/py-pydantic2@${PY_FLAVOR}

USES=		cmake:indirect python localbase pkgconfig
USE_PYTHON=	autoplist concurrent pep517

CMAKE_ARGS=	-DUSE_SYSTEM_DEPS=ON

post-extract:
	@${MKDIR} ${WRKSRC}/cpp/include
	@${CP} ${FILESDIR}/cpp_include/*.h ${WRKSRC}/cpp/include/

.include <bsd.port.mk>
