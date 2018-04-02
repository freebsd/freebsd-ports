# $FreeBSD$

PORTNAME=	openpiv
PORTVERSION=	0.20.9
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Python module for Particle Image Velocimetry

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PY_FUTURE} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0.12.0:graphics/py-scikit-image@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}progressbar2>=3.8.1:misc/py-progressbar2@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils cython cython_run
USE_GITHUB=	yes
GH_ACCOUNT=	OpenPIV
GH_PROJECT=	openpiv-python

post-patch:
# Do not install supplementing data to allow concurrent installion
	${REINPLACE_CMD} -e '/data_files = data_files,/d' ${WRKSRC}/setup.py

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
PY_FUTURE=	${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${FLAVOR}
.else
PY_FUTURE=
.endif

.include <bsd.port.post.mk>
