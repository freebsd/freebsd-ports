# Created by: Jie Gao <gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	qtiplot
DISTVERSION=	0.9.8.9
PORTREVISION=	8
CATEGORIES=	math science
MASTER_SITES=	BERLIOS http://soft.proindependent.com/src/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data analysis and scientific plotting

LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl \
		libmuparser.so:${PORTSDIR}/math/muparser \
		libpng15.so:${PORTSDIR}/graphics/png
# use bundled modified libraries
# 		qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
# 		qwtplot3d-qt4:${PORTSDIR}/math/qwtplot3d-qt4

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
OPTIONS_DEFAULT=	DOCS PYTHON NLS

DOCS_DESC=	Install the QtiPlot Handbook
PYTHON_DESC=	Python scripting support

STRIP_FILES=	bin/qtiplot share/qtiplot/fitPlugins/*.so.1.0.0

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
PLIST_SUB+=	PYTHON=""
CONFIGURE_ENV+=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR} \
		PYTHON_VERSION=${PYTHON_VERSION}
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
RUN_DEPENDS+=	qtiplot-doc>=0:${PORTSDIR}/math/qtiplot-doc
USE_QT4+=	assistant-adp_run
.endif

.if ${PORT_OPTIONS:MNLS}
USE_QT4+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	${CP} ${FILESDIR}/build.conf ${WRKSRC}

post-patch:
.if ${PORT_OPTIONS:MPYTHON}
	${REINPLACE_CMD} -e \
		'/^sys.path.append/s|"\."|"${DATADIR}"|' \
		${WRKSRC}/${PORTNAME}/qtiplotrc.py
.else
	${REINPLACE_CMD} -e \
		"s/SCRIPTING_LANGS.*Python//" \
		${WRKSRC}/build.conf
.endif
	${REINPLACE_CMD} -e \
		's|/usr/local/qtiplot/fitPlugins|${DATADIR}/fitPlugins|' \
		${WRKSRC}/qtiplot/src/core/ApplicationWindow.cpp
	${REINPLACE_CMD} -e \
		's|target.path=.*|target.path=${DATADIR}/fitPlugins|g' \
		${WRKSRC}/fitPlugins/*/*.pro
	${REINPLACE_CMD} -e '/^system($$$$LUPDATE/d; /^system($$$$LRELEASE/d' \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.if ${PORT_OPTIONS:MDEBUG}
	${REINPLACE_CMD} -e \
		"/^CONFIG.*release/s|release|debug|" \
		${WRKSRC}/build.conf
.endif
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e \
		"/INSTALLS.*translations/d" \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.endif

pre-configure:
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC}/qtiplot && ${LRELEASE} -compress qtiplot.pro
.endif

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}
	${INSTALL_DATA} ${WRKSRC}/qtiplot_logo.png ${STAGEDIR}${PREFIX}/share/pixmaps/qtiplot.png
.if ${PORT_OPTIONS:MPYTHON}
.for s in qtiplotrc.py qtiUtil.py
	cd ${WRKSRC}/qtiplot && ${PYTHON_CMD} -c "import py_compile; py_compile.compile('${s}')"
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${s}c ${STAGEDIR}${DATADIR}/${s}c
.endfor
.endif

.include <bsd.port.mk>
