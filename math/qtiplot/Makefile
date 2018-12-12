# Created by: Jie Gao <gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	qtiplot
DISTVERSION=	0.9.8.9
PORTREVISION=	17
CATEGORIES=	math science
MASTER_SITES=	BERLIOS http://soft.proindependent.com/src/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data analysis and scientific plotting

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libgsl.so:math/gsl \
		libmuparser.so:math/muparser \
		libpng.so:graphics/png
# use bundled modified libraries
#		qwt.5:x11-toolkits/qwt5 \
#		qwtplot3d-qt4:math/qwtplot3d-qt4

USES=		compiler:c++11-lang dos2unix gmake qmake qt:4 tar:bzip2
USE_QT=		gui opengl svg qt3support network assistantclient \
		moc_build rcc_build
USE_GL=		glu
QMAKE_ARGS+=	LOCALBASE=${LOCALBASE} PYTHON_CMD=${PYTHON_CMD}
DOS2UNIX_GLOB=	*.pro

DESKTOP_ENTRIES="QtiPlot" "Data analysis and plotting" \
		"${PREFIX}/share/pixmaps/qtiplot.png" \
		"qtiplot" "" true

OPTIONS_DEFINE=	DOCS PYTHON NLS
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=	yes

DOCS_DESC=	Install the QtiPlot Handbook
DOCS_RUN_DEPENDS=	qtiplot-doc>=0:math/qtiplot-doc
DOCS_USES=	qt:4
DOCS_USE=	QT=assistant-adp_run

PYTHON_DESC=	Python scripting support
PYTHON_USES=	pyqt:4 python:2.7
PYTHON_USE=	pyqt=gui
PYTHON_CONFIGURE_ENV=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR} \
			PYTHON_VERSION=${PYTHON_VERSION}

NLS_USES=	qt:4
NLS_USE=	QT=linguisttools_build

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
# fix build with clang6
	${REINPLACE_CMD} \
		-e '/new[[:space:]]*QComboBox/s,false,,g' \
		-e '/new[[:space:]]*PatternBox/s,false,,g' \
		${WRKSRC}/qtiplot/src/matrix/MatrixValuesDialog.cpp \
		${WRKSRC}/qtiplot/src/plot2D/dialogs/LayerDialog.cpp \
		${WRKSRC}/qtiplot/src/plot2D/dialogs/PlotDialog.cpp \
		${WRKSRC}/qtiplot/src/table/SetColValuesDialog.cpp \
		${WRKSRC}/qtiplot/src/table/TableDialog.cpp

post-patch-PYTHON-off:
	${REINPLACE_CMD} -e \
		"s/SCRIPTING_LANGS.*Python//" \
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
