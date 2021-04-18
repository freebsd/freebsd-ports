PORTNAME=	nilearn
DISTVERSION=	0.7.1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Statistical learning for neuroimaging in Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nibabel>0:science/py-nibabel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		bash:shells/bash

USES=		python:3.7+ shebangfix
USE_PYTHON=	distutils autoplist

SHEBANG_FILES=	nilearn/datasets/tests/data/list_archive_contents.sh

NO_ARCH=	yes

.include <bsd.port.mk>
