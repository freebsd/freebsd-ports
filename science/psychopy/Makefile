# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	psychopy
PORTVERSION=	1.83.04
PORTREVISION=	1
CATEGORIES=	science python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Psychophysics toolkit for Python

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.6.0:science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:textproc/py-openpyxl \
		dejavu>0:x11-fonts/dejavu \
		${PYGAME} \
		${PYNUMPY}

NO_ARCH=	yes

USE_GITHUB=	yes

USES=		fortran python
USE_PYTHON=	autoplist distutils
USE_WX=		2.8
WX_COMPS=	python

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
PYGLET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyglet>=1.1.2:graphics/py-pyglet

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
