PORTNAME=	mdp
DISTVERSION=	3.6
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modular toolkit for Data Processing
WWW=		https://mdp-toolkit.sourceforge.net/

LICENSE=	BSD3CLAUSE

DEPRECATED=	No upstream activity since 2020
EXPIRATION_DATE=	2026-08-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	LIBSVM SCIPY

LIBSVM_DESC=	Provide the LibSVMClassifier node
SCIPY_DESC=	Instal SciPy versions of eigensolver, FFT and convolution

LIBSVM_RUN_DEPENDS=	libsvm>2.91:science/libsvm \
			libsvm-python>2.91:science/libsvm-python
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.5.2:science/py-scipy@${PY_FLAVOR}

.include <bsd.port.mk>
