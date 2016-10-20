# Created by: Jie Gao <gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	qtiplot
DISTVERSION=	0.9.8.9
PORTREVISION=	10
CATEGORIES=	math science
MASTER_SITES=	BERLIOS http://soft.proindependent.com/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data analysis and scientific plotting

LIB_DEPENDS=	libgsl.so:math/gsl \
		libmuparser.so:math/muparser \
		libpng.so:graphics/png
# use bundled modified libraries
# 		qwt.5:x11-toolkits/qwt5 \
# 		qwtplot3d-qt4:math/qwtplot3d-qt4

USES=		dos2unix gmake qmake tar:bzip2
USE_QT4=	gui opengl svg qt3support network assistantclient \
		moc_build rcc_build
USE_GL=		glu
QMAKE_ARGS+=	LOCALBASE=${LOCALBASE} PYTHON_CMD=${PYTHON_CMD}
DOS2UNIX_GLOB=	*.pro

DESKTOP_ENTRIES="QtiPlot" "Data analysis and plotting" \
		"${PREFIX}/share/pixmaps/qtiplot.png" \
		"qtiplot" "" true

OPTIONS_DEFINE=	DOCS PYTHON NLS DEBUG
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=	yes

DOCS_DESC=	Install the QtiPlot Handbook
DOCS_RUN_DEPENDS=	qtiplot-doc>=0:math/qtiplot-doc
DOCS_USE=	QT4=assistant-adp_run

PYTHON_DESC=	Python scripting support
PYTHON_USES=	python
PYTHON_BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:x11-toolkits/py-qt4-gui
PYTHON_RUN_DEPENDS:=	${PYTHON_BUILD_DEPENDS}
PYTHON_CONFIGURE_ENV=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR} \
			PYTHON_VERSION=${PYTHON_VERSION}

NLS_USE=	QT4=linguisttools_build

post-extract:
	${CP} ${FILESDIR}/build.conf ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		's|/usr/local/qtiplot/fitPlugins|${DATADIR}/fitPlugins|' \
		${WRKSRC}/qtiplot/src/core/ApplicationWindow.cpp
	${REINPLACE_CMD} -e \
		's|target.path=.*|target.path=${DATADIR}/fitPlugins|g' \
		${WRKSRC}/fitPlugins/*/*.pro
	${REINPLACE_CMD} -e '/^system($$$$LUPDATE/d; /^system($$$$LRELEASE/d' \
		${WRKSRC}/${PORTNAME}/qtiplot.pro

post-patch-PYTHON-on:
	${REINPLACE_CMD} -e \
		'/^sys.path.append/s|"\."|"${DATADIR}"|' \
		${WRKSRC}/${PORTNAME}/qtiplotrc.py

post-patch-PYTHON-off:
	${REINPLACE_CMD} -e \
		"s/SCRIPTING_LANGS.*Python//" \
		${WRKSRC}/build.conf

post-patch-DEBUG-on:
	${REINPLACE_CMD} -e \
		"/^CONFIG.*release/s|release|debug|" \
		${WRKSRC}/build.conf

post-patch-NLS-off:
	${REINPLACE_CMD} -e \
		"/INSTALLS.*translations/d" \
		${WRKSRC}/${PORTNAME}/qtiplot.pro

pre-configure-NLS-on:
	cd ${WRKSRC}/qtiplot && ${LRELEASE} -compress qtiplot.pro

post-install:
	${INSTALL_DATA} ${WRKSRC}/qtiplot_logo.png ${STAGEDIR}${PREFIX}/share/pixmaps/qtiplot.png

post-install-PYTHON-on:
.for s in qtiplotrc.py qtiUtil.py
	cd ${WRKSRC}/qtiplot && ${PYTHON_CMD} -c "import py_compile; py_compile.compile('${s}')"
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${s}c ${STAGEDIR}${DATADIR}/${s}c
.endfor

.include <bsd.port.mk>
