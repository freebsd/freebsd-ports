# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	scikit-optimize
PORTVERSION=	0.8.1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sequential model-based optimization toolbox

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}joblib>=0.11:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.13.3,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>=16.9:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.20.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.19.1:science/py-scipy@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	PLOTS
PLOTS_DESC=	Plotting support

PLOTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=2.0.0:math/py-matplotlib@${PY_FLAVOR}

.include <bsd.port.mk>
