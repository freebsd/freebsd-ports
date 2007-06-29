# New ports collection makefile for:	qtiplot
# Date created:			9 May 2005
# Whom:				Jie Gao <gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	qtiplot
DISTVERSION=	0.9rc2
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	http://soft.proindependent.com/src/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	An Origin clone for data analysis and scientific plotting

LIB_DEPENDS=	gsl.10:${PORTSDIR}/math/gsl \
		muparser.0:${PORTSDIR}/math/muparser \
		origin.0:${PORTSDIR}/math/liborigin \
		qwtplot3d-qt4:${PORTSDIR}/math/qwtplot3d-qt4 \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt-devel

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc qmake opengl qt3support network assistantclient
HAS_CONFIGURE=	yes
USE_DOS2UNIX=	qtiplot/qtiplot.pro

DESKTOP_ENTRIES="QtiPlot" "Data analysis and plotting" \
		"${DATADIR}/manual/common/qtiplot_logo.png" \
		"qtiplot" "" false

OPTIONS=	DOCS "Install the QtiPlot Handbook" on \
		PYTHON "Python scripting support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PYTHON)
BROKEN=	py-qt4-\* ports should be fixed first
USE_PYTHON=	yes
# manually include this, because USE_PYTHON is defined
# after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.python.mk"
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
PLIST_SUB+=	PYTHON=""
MAKE_ENV+=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR} \
		PYTHON_VERSION=${PYTHON_VERSION}
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if !defined(WITHOUT_DOCS)
RUN_DEPENDS+=	qtiplot-doc>=0:${PORTSDIR}/math/qtiplot-doc
.endif

.if !defined(WITHOUT_NLS)
#QT_COMPONENTS+=	linguist
BUILD_DEPENDS+=	${LOCALBASE}/bin/lupdate-qt4:${PORTSDIR}/devel/qt4-linguist
QTI_LANG=	de es fr ja ru sv
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

QPRO_DIRS=	. \
		fitPlugins/fitRational0 \
		fitPlugins/fitRational1 \
		qtiplot

post-patch:
.if defined(WITH_PYTHON)
	@${REINPLACE_CMD} -e \
		's|loadInitFile("qtiplotrc")|loadInitFile("${DATADIR}/qtiplotrc")|' \
		${WRKSRC}/${PORTNAME}/src/PythonScripting.cpp
.else
	@${REINPLACE_CMD} \
		-e "s/^SCRIPTING_LANGS += Python//" \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.endif

do-configure:
.for d in ${QPRO_DIRS}
	(cd ${WRKSRC}/${d} && ${SETENV} ${MAKE_ENV} ${QMAKE})
.endfor

post-configure:
.for d in ${QPRO_DIRS}
	@${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|^LINK .*|LINK=${CXX}|; \
		 s|-pipe||; \
		 s|^\(CFLAGS .*= \)|\1${CFLAGS}|; \
		 s|^\(CXXFLAGS = \)|\1${CXXFLAGS}|' \
		${WRKSRC}/${d}/Makefile
.endfor

do-build:
.for d in ${QPRO_DIRS}
	(cd ${WRKSRC}/${d}; ${SETENV} ${MAKE_ENV} ${GMAKE})
.endfor

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/qtiplot/qtiplot ${DATADIR}/qtiplot
	${LN} -fs ${DATADIR}/qtiplot ${PREFIX}/bin/qtiplot
	${MKDIR} ${DATADIR}/fitPlugins
	${INSTALL_PROGRAM} ${WRKSRC}/fitPlugins/libfitRational0.so.1.0.0 \
				${DATADIR}/fitPlugins/libfitRational0.so
	${INSTALL_PROGRAM} ${WRKSRC}/fitPlugins/libfitRational1.so.1.0.0 \
				${DATADIR}/fitPlugins/libfitRational1.so
.if defined(WITH_PYTHON)
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/qtiplotrc.py ${DATADIR}/qtiplotrc.py
	@cd ${WRKSRC}/qtiplot && ${PYTHON_CMD} -c "import py_compile; py_compile.compile('qtiplotrc.py')"
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/qtiplotrc.pyc ${DATADIR}/qtiplotrc.pyc
.endif
.if !defined(WITHOUT_NLS)
	(cd ${WRKSRC}/qtiplot/translations/ && ${COPYTREE_SHARE} '*.qm' ${DATADIR}/translations)
.endif

.include <bsd.port.post.mk>
