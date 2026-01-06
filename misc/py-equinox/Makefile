PORTNAME=	equinox
DISTVERSION=	0.13.2
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Elegant easy-to-use neural networks in JAX
WWW=		https://docs.kidger.site/equinox/ \
		https://github.com/patrick-kidger/equinox

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jax>=0.4.38:math/py-jax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaxtyping>=0.2.20:devel/py-jaxtyping@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wadler-lindig>=0.1.0:devel/py-wadler-lindig@${PY_FLAVOR}
#TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beartype>0:devel/py-beartype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaxlib>0:math/py-jaxlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}optax>0:math/py-optax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
