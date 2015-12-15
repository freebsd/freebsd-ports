# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	psychopy
PORTVERSION=	1.83.01
CATEGORIES=	science python
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Psychophysics toolkit for Python

LICENSE=	GPLv3 # (or later)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}pyglet>=1.1.2:${PORTSDIR}/graphics/py-pyglet \
		${PYTHON_PKGNAMEPREFIX}pandas>0:${PORTSDIR}/math/py-pandas \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.6.0:${PORTSDIR}/science/py-scipy \
		dejavu>0:${PORTSDIR}/x11-fonts/dejavu \
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

.include <bsd.port.options.mk>
post-patch:
# https://github.com/psychopy/psychopy/issues/982
	@${REINPLACE_CMD} -e \
		's|str(,id_dict)|str(id.dict)|' \
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
