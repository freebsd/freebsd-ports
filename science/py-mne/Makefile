PORTNAME=	mne
PORTVERSION=	1.11.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python project for MEG and EEG data analysis
WWW=		https://mne.tools/stable/ \
		https://github.com/mne-tools/mne-python

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazy_loader>=0.3:devel/py-lazy_loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.8:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pooch>=1.5:devel/py-pooch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.11:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

# tests as of 1.10.1: pytest tests available but require extra dependencies, skipped for packaging

.include <bsd.port.mk>
