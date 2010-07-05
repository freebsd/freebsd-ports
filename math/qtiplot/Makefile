# New ports collection makefile for:	qtiplot
# Date created:			9 May 2005
# Whom:				Jie Gao <gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	qtiplot
DISTVERSION=	0.9.8
CATEGORIES=	math science
MASTER_SITES=	BERLIOS http://soft.proindependent.com/src/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	An Origin clone for data analysis and scientific plotting

BUILD_DEPENDS=	${LOCALBASE}/lib/libmuparser.a:${PORTSDIR}/math/muparser
LIB_DEPENDS=	gsl.15:${PORTSDIR}/math/gsl \
		boost_date_time:${PORTSDIR}/devel/boost-libs
# use bundled modified libraries
# 		qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
# 		qwtplot3d-qt4:${PORTSDIR}/math/qwtplot3d-qt4

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui opengl svg qt3support network assistantclient \
		moc_build qmake_build rcc_build
HAS_CONFIGURE=	yes
QMAKE_ARGS+=	-unix -recursive PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} \
		PYTHON_CMD=${PYTHON_CMD}
USE_DOS2UNIX=	*.pro
MAKE_JOBS_SAFE=	yes
MAN1=		qtiplot.1

DESKTOP_ENTRIES="QtiPlot" "Data analysis and plotting" \
		"${DATADIR}/qtiplot.png" \
		"qtiplot" "" false

OPTIONS=	DOCS "Install the QtiPlot Handbook" on \
		PYTHON "Python scripting support" on

STRIP_FILES=	bin/qtiplot share/qtiplot/fitPlugins/*.so.1.0.0

.include <bsd.port.options.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
PLIST_SUB+=	PYTHON=""
CONFIGURE_ENV+=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR} \
		PYTHON_VERSION=${PYTHON_VERSION}
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if !defined(WITHOUT_DOCS)
RUN_DEPENDS+=	qtiplot-doc>=0:${PORTSDIR}/math/qtiplot-doc
QT_COMPONENTS+=	assistant-adp_run
.endif

.if !defined(WITHOUT_NLS)
QT_COMPONENTS+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${FILESDIR}/build.conf ${WRKSRC}

post-patch:
.if defined(WITH_PYTHON)
	@${REINPLACE_CMD} -e \
		'/^sys.path.append/s|"\."|"${DATADIR}"|' \
		${WRKSRC}/${PORTNAME}/qtiplotrc.py
.else
	@${REINPLACE_CMD} -e \
		"s/SCRIPTING_LANGS.*Python//" \
		${WRKSRC}/build.conf
.endif
	@${REINPLACE_CMD} -e \
		's|/usr/lib/qtiplot/plugins|${DATADIR}/fitPlugins|' \
		${WRKSRC}/qtiplot/src/core/ApplicationWindow.cpp
	@${REINPLACE_CMD} -e \
		's|target.path=.*|target.path=${DATADIR}/fitPlugins|g' \
		${WRKSRC}/fitPlugins/*/*.pro
	@${REINPLACE_CMD} -e '/^system($$$$LUPDATE/d; /^system($$$$LRELEASE/d' \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.if defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e \
		"/^CONFIG.*release/s|release|debug|" \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.endif
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e \
		"/INSTALLS.*translations/d" \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.endif

do-configure:
.if !defined(WITHOUT_NLS)
	@(cd ${WRKSRC}/qtiplot && ${LOCALBASE}/bin/lrelease-qt4 -compress qtiplot.pro)
.endif
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS} )

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}
	${INSTALL_DATA} ${WRKSRC}/qtiplot_logo.png ${DATADIR}/qtiplot.png
.if defined(WITH_PYTHON)
.for s in qtiplotrc.py qtiUtil.py
	@(cd ${WRKSRC}/qtiplot && ${PYTHON_CMD} -c "import py_compile; py_compile.compile('${s}')")
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${s}c ${DATADIR}/${s}c
.endfor
.endif

.include <bsd.port.post.mk>
