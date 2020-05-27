# $FreeBSD$

PORTNAME=	scidavis
PORTVERSION=	2.2.0
CATEGORIES=	science

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scientific data analysis and visualization

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgsl.so:math/gsl \
		libmuparser.so:math/muparser \
		libpng.so:graphics/png \
		libqwt5-qt5.so:x11-toolkits/qwt5-qt5 \
		libqwtplot3d-qt5.so:math/qwtplot3d \
		liborigin.so:math/liborigin

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5 \
		shared-mime-info
USE_GL=		gl glu
USE_QT=		core gui network opengl printsupport svg widgets xml \
		buildtools_build linguisttools_build

USE_GITHUB=	yes
GH_ACCOUNT=	highperformancecoder

QMAKE_ARGS=	INSTALLBASE=${PREFIX} \
		CONFIG+=liborigin \
		LIBS+="-L${LOCALBASE}/${QT_LIBDIR_REL} -L${LOCALBASE}/lib" \
		LIBS+="-lqwt5-qt5 -lqwtplot3d-qt5" \
		INCLUDEPATH+=${LOCALBASE}/${QT_INCDIR_REL}/qwt5-qt5 \
		INCLUDEPATH+=${LOCALBASE}/${QT_INCDIR_REL}/qwtplot3d-qt5

OPTIONS_DEFINE=	DOCS NLS PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=	yes

PYTHON_DESC=	Python scripting support
PYTHON_USES=	pyqt:5 python
PYTHON_USE=	pyqt=core,gui,printsupport,sip,widgets python=py3kplist
PYTHON_QMAKE_ON=	PYTHON=${PYTHON_CMD} CONFIG+=python \
			PYQT_SIPDIR=${LOCALBASE}/${_SIPDIR_REL}

post-patch:
	${REINPLACE_CMD} '/target.path/s,/usr/lib,${PREFIX}/lib,' \
		${WRKSRC}/fitPlugins/*/*.pro
	${REINPLACE_CMD} 's,share/man,man,' \
		${WRKSRC}/config.pri \
		${WRKSRC}/scidavis/scidavis.pro

post-install-NLS-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/scidavis/translations/*.qm \
		${STAGEDIR}${DATADIR}/translations

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPYTHON}
.if ${PYTHON_REL} < 3200
PYCACHE_DIR=	# none
PYCACHE_FILE=	scidavisUtil.pyc
.else
PYCACHE_DIR=	__pycache__/
PYCACHE_FILE=	scidavisUtil.cpython-${PYTHON_SUFFIX}.pyc
.endif
.endif

post-install-PYTHON-on:
	${MV} ${STAGEDIR}${PREFIX}/etc/scidavisrc.py \
		${STAGEDIR}${PREFIX}/etc/scidavisrc.py.sample
	${MKDIR} ${STAGEDIR}${DATADIR}/${PYCACHE_DIR}
	${INSTALL_DATA} ${WRKSRC}/scidavis/${PYCACHE_DIR}${PYCACHE_FILE} \
		${STAGEDIR}${DATADIR}/${PYCACHE_DIR}

.include <bsd.port.post.mk>
