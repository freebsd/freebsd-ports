# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	psychopy
DISTVERSION=	1.90.3
PORTREVISION=	2
CATEGORIES=	science python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Psychophysics toolkit for Python

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}json_tricks>0:devel/py-json_tricks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyglet>0:graphics/py-pyglet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyosf>0:science/py-pyosf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sounddevice>0:audio/py-sounddevice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SoundFile>0:audio/py-SoundFile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>0:textproc/py-xlrd@${PY_FLAVOR} \
		dejavu>0:x11-fonts/dejavu \
		${PYGAME} \
		${PYNUMPY}

USES=		fortran python:2.7
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
USE_WX=		2.8
WX_COMPS=	python
NO_ARCH=	yes

PLIST_FILES=	bin/psychopy

DESKTOP_ENTRIES="PsychoPy" \
		"" \
		"${PYTHONPREFIX_SITELIBDIR}/psychopy/app/Resources/psychopy.png" \
		"psychopy" \
		"" \
		""

OPTIONS_DEFINE_i386=	PYGLET
OPTIONS_DEFAULT_i386=	PYGLET

PYGLET_DESC=		Drawing support via Pyglet
PYGLET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyglet>=1.1.2:graphics/py-pyglet@${PY_FLAVOR}

.include <bsd.port.options.mk>

post-patch:
# https://github.com/psychopy/psychopy/issues/982
	@${REINPLACE_CMD} -e \
		's|str(,id_dict)|str(id_dict)|' \
		${WRKSRC}/psychopy/demos/coder/iohub/elotouchscreen/run.py

post-build:
	@${ECHO_CMD} -n > ${WRKDIR}/psychopy
	@${ECHO_CMD} "#!${SH}" \
		>> ${WRKDIR}/psychopy
.if ${OPSYS} == FreeBSD
	@${ECHO_CMD} "LD_LIBRARY_PATH=${LOCALBASE}/lib/${FC:S/fortran/cc/}:\$$LD_LIBRARY_PATH" \
		>> ${WRKDIR}/psychopy
	@${ECHO_CMD} "export LD_LIBRARY_PATH" \
		>> ${WRKDIR}/psychopy
.endif
	@${ECHO_CMD} \
		>> ${WRKDIR}/psychopy
	@${ECHO_CMD} "${PYTHON_CMD} ${PREFIX}/bin/psychopyApp.py" \
		>> ${WRKDIR}/psychopy

post-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} psychopy \
		${STAGEDIR}${PREFIX}/bin)
	@${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psychopy/app/Resources/DejaVuSerif.ttf
	@${LN} -sf ${LOCALBASE}/share/fonts/dejavu/DejaVuSerif.ttf \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psychopy/app/Resources

.include <bsd.port.mk>
