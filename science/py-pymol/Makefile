# Created by: Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
# $FreeBSD$

PORTNAME=	pymol
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	science biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenGL-based molecular visualization system

LICENSE=	PyMOL
LICENSE_NAME=	Open-Source PyMOL Copyright
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		${LOCALBASE}/include/mmtf.hpp:science/mmtf-cpp
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libmsgpackc.so:devel/msgpack
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pmw>0:x11-toolkits/py-Pmw@${PY_FLAVOR} \
		${PYNUMPY}

USES=		compiler:c++11-lang gl gnome python:2.7 shebangfix tar:bz2
USE_GITHUB=	yes
GH_ACCOUNT=	schrodinger
GH_PROJECT=	${PORTNAME}-open-source
USE_GL=		gl glew glu glut
USE_GNOME=	libxml2
USE_PYTHON=	distutils concurrent # autoplist is broken: https://sourceforge.net/p/pymol/bugs/189
SHEBANG_FILES=	test/show test/run test/cyg

OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	QT5 TK
OPTIONS_DEFAULT=	QT5

QT5_USES=	pyqt:5
QT5_USE=	PYQT=core_run,gui_run,opengl_run

post-patch-TK-on:
	@${REINPLACE_CMD} -e ' \
		23s|if not PYQT_NAME:|if False:| ; \
		s|from PyQt5 import|from X import|' \
		${WRKSRC}/modules/${PORTNAME}/Qt/__init__.py

post-install:
	@${REINPLACE_CMD} -i '' -e 's|#!/bin/bash|#!/bin/sh|' ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/_cmd.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/chempy/champ/_champ.so

.include <bsd.port.mk>
