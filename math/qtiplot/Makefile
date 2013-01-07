# Created by: Jie Gao <gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	qtiplot
DISTVERSION=	0.9.8.9
PORTREVISION=	2
CATEGORIES=	math science
MASTER_SITES=	BERLIOS http://soft.proindependent.com/src/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data analysis and scientific plotting

BUILD_DEPENDS=	${LOCALBASE}/lib/libmuparser.a:${PORTSDIR}/math/muparser
LIB_DEPENDS=	gsl.16:${PORTSDIR}/math/gsl \
		png15:${PORTSDIR}/graphics/png
# use bundled modified libraries
# 		qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
# 		qwtplot3d-qt4:${PORTSDIR}/math/qwtplot3d-qt4

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT4=	gui opengl svg qt3support network assistantclient \
		moc_build qmake_build rcc_build
USE_GL=		glu
HAS_CONFIGURE=	yes
QMAKE_ARGS+=	-recursive PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} \
		PYTHON_CMD=${PYTHON_CMD}
USE_DOS2UNIX=	*.pro
MAKE_JOBS_SAFE=	yes
MAN1=		qtiplot.1

DESKTOP_ENTRIES="QtiPlot" "Data analysis and plotting" \
		"${DATADIR}/qtiplot.png" \
		"qtiplot" "" false

OPTIONS_DEFINE=	DOCS PYTHON
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

DOCS_DESC=	Install the QtiPlot Handbook
PYTHON_DESC=	Python scripting support

STRIP_FILES=	bin/qtiplot share/qtiplot/fitPlugins/*.so.1.0.0

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
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

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${FILESDIR}/build.conf ${WRKSRC}

post-patch:
.if ${PORT_OPTIONS:MPYTHON}
	@${REINPLACE_CMD} -e \
		'/^sys.path.append/s|"\."|"${DATADIR}"|' \
		${WRKSRC}/${PORTNAME}/qtiplotrc.py
.else
	@${REINPLACE_CMD} -e \
		"s/SCRIPTING_LANGS.*Python//" \
		${WRKSRC}/build.conf
.endif
	@${REINPLACE_CMD} -e \
		's|/usr/local/qtiplot/fitPlugins|${DATADIR}/fitPlugins|' \
		${WRKSRC}/qtiplot/src/core/ApplicationWindow.cpp
	@${REINPLACE_CMD} -e \
		's|target.path=.*|target.path=${DATADIR}/fitPlugins|g' \
		${WRKSRC}/fitPlugins/*/*.pro
	@${REINPLACE_CMD} -e '/^system($$$$LUPDATE/d; /^system($$$$LRELEASE/d' \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.if defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e \
		"/^CONFIG.*release/s|release|debug|" \
		${WRKSRC}/build.conf
.endif
.if !${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e \
		"/INSTALLS.*translations/d" \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.endif

do-configure:
.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/qtiplot && ${LOCALBASE}/bin/lrelease-qt4 -compress qtiplot.pro)
.endif
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS} )

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}
	${INSTALL_DATA} ${WRKSRC}/qtiplot_logo.png ${DATADIR}/qtiplot.png
.if ${PORT_OPTIONS:MPYTHON}
.for s in qtiplotrc.py qtiUtil.py
	@(cd ${WRKSRC}/qtiplot && ${PYTHON_CMD} -c "import py_compile; py_compile.compile('${s}')")
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${s}c ${DATADIR}/${s}c
.endfor
.endif

.include <bsd.port.post.mk>
