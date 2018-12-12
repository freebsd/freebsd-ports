# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MOOSE-neural-simulator
DISTVERSION=	3.1.2
PORTREVISION=	6
DISTVERSIONSUFFIX=	-382-gc93d23a
CATEGORIES=	science biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiphysics Object Oriented Simulation Environment

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libsbml.so:biology/libsbml \
		libsz.so:science/szip
BUILD_DEPENDS=	bash:shells/bash \
		${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.1.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=1.0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygraphviz>=0:graphics/py-pygraphviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}suds-jurko>=0.4:net/py-suds-jurko@${PY_FLAVOR}

USES=		cmake:outsource fortran gettext-runtime pyqt:4 python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	BhallaLab
GH_PROJECT=	moose
USE_PYQT=	core_run gui_run test_run

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's|DESTINATION lib/moose/moose-examples|DESTINATION share/examples/${PORTNAME}|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|\.\./moose-examples/|${EXAMPLESDIR}/|' ${WRKSRC}/moose-gui/mgui.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/moose/_moose.so

.include <bsd.port.mk>
