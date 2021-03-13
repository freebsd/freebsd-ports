# $FreeBSD$

PORTNAME=	orange3
DISTVERSION=	3.28.0
CATEGORIES=	misc python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Component-based data mining software

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}AnyQt>=0.0.8:x11-toolkits/py-AnyQt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}baycomp>=1.0.2:math/py-baycomp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bottleneck>=1.0.0:math/py-bottleneck@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=3.0.2:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=0.9.4:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.14.0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyrings.alt>0:security/py-keyrings.alt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.0.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openTSNE>=0.4.3:math/py-openTSNE@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orange-canvas-core>=0.1.19:devel/py-orange-canvas-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orange-widget-base>=4.12.0:devel/py-orange-widget-base@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.0.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-louvain>=0.13:math/py-python-louvain@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyqtgraph>=0.11.0:graphics/py-pyqtgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.22.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.16.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}serverfiles>0:misc/py-serverfiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=0.9.2:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>0:misc/py-XlsxWriter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.4+ pyqt:5
USE_PYTHON=	distutils cython autoplist noflavors
USE_PYQT=	core_run gui_run printsupport_run widgets_run webengine_run

USE_GITHUB=	yes
GH_ACCOUNT=	biolab

CFLAGS+=	-DQSORT_R_STYLE_BSD=yes
LDFLAGS+=	-Xlinker -strip-all # strip, stage-qa doesn't catch that it isn't stripped

xpost-install:
	@${REINPLACE_CMD} -e 's|^"${PREFIX}/|| ; s|"$$||' ${_PYTHONPKGLIST} # https://github.com/biolab/orange3/issues/3060
	@${REINPLACE_CMD} -e 's|import sys|& ; from OpenGL import GL|' ${STAGEDIR}${PREFIX}/bin/orange-canvas # https://github.com/biolab/orange3/issues/3062

.include <bsd.port.mk>
