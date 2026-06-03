PORTNAME=	osqp
DISTVERSION=	1.1.1
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Operator Splitting QP Solver
WWW=		https://osqp.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.11:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		cmake:devel/cmake-core
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.7:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.13.2:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist
USE_GITHUB=	nodefault
GH_TUPLE=	osqp:osqp:v1.0.0:osqp \
		osqp:qdldl:v0.1.8:qdldl

pre-configure:
	@${LN} -sf ${WRKSRC_osqp} ${WRKSRC}/osqp-source
	@${LN} -sf ${WRKSRC_qdldl} ${WRKSRC}/qdldl-source

.include <bsd.port.mk>
