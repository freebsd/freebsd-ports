# $FreeBSD$

PORTNAME=	openpiv
PORTVERSION=	0.20.9
PORTREVISION=	1
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Python module for Particle Image Velocimetry

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PY_FUTURE} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0.12.0:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}progressbar2>=3.8.1:misc/py-progressbar2@${PY_FLAVOR}

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
PY_FUTURE=	${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR}
.else
PY_FUTURE=
.endif

.include <bsd.port.post.mk>
