PORTNAME=	dwave-optimization
DISTVERSION=	0.1.0
CATEGORIES=	science python # quantum-computing
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Nonlinear models for industrial optimization problems
WWW=		https://github.com/dwavesystems/dwave-optimization

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython3>0:lang/cython3@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}setuptools-dso>=2.10:devel/py-setuptools-dso@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}reno>=4.1.0:textproc/py-reno@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist

POST_PLIST=	fix-plist

post-install:
	# strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/libdwave-optimization.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/model${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/optimization/symbols${PYTHON_EXT_SUFFIX}.so
	# remove conflicting __init__.py, see https://github.com/dwavesystems/dwave-system/issues/462
	@${RM} -r \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/__init__.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/dwave/__pycache__

fix-plist:
	@${REINPLACE_CMD} -e " \
		s|.*dwave/__init__\.py||; \
		s|.*dwave/__pycache__/.*|| \
		" ${TMPPLIST}

.include <bsd.port.mk>
