# New ports collection makefile for:	qtiplot
# Date created:			9 May 2005
# Whom:				Jie Gao <gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	qtiplot
PORTVERSION=	0.8.9.r2
CATEGORIES=	math science
MASTER_SITES=	http://soft.proindependent.com/src/
DISTNAME=	${PORTNAME}-0.8.9-rc2

MAINTAINER=	makc@issp.ac.ru
COMMENT=	An Origin clone for data analysis and scientific plotting

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	gsl.9:${PORTSDIR}/math/gsl \
		origin.0:${PORTSDIR}/math/liborigin \
		qwtplot3d:${PORTSDIR}/math/qwtplot3d \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt-devel

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
MAKE_ENV=	QTDIR=${QT_PREFIX}

DESKTOP_ENTRIES="QtiPlot" "Data analysis and plotting" \
		"${DOCSDIR}/common/qtiplot_logo.png" \
		"qtiplot" "" false

OPTIONS=	DOCS "Install the QtiPlot Handbook" on \
		PYTHON "Python scripting support" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on FreeBSD 4.x
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	2.4
# manually include this, because USE_PYTHON is defined
# after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.python.mk"
BUILD_DEPENDS+=	sip:${PORTSDIR}/devel/py-sip \
		${PYTHON_SITELIBDIR}/qt.so:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/qt.so:${PORTSDIR}/x11-toolkits/py-qt
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if !defined(WITHOUT_DOCS)
RUN_DEPENDS+=	qtiplot-doc>=0:${PORTSDIR}/math/qtiplot-doc
.endif

.if !defined(WITHOUT_NLS)
QTI_LANG=	de es fr ru sv
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

QMAKE=		qmake
QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

QPRO_DIRS=	. \
		fitPlugins/fitRational0 \
		fitPlugins/fitRational1 \
		qtiplot

post-patch:
.if defined(WITH_PYTHON)
	@${REINPLACE_CMD} \
		-e "s:/usr/include/python2.4:${PYTHON_INCLUDEDIR}:" \
		-e "s:/usr/share/sip:${LOCALBASE}/share/py-sip/:" \
		${WRKSRC}/qtiplot/qtiplot.pro
	@${REINPLACE_CMD} -e \
		's|loadInitFile("qtiplotrc")|loadInitFile("${DATADIR}/qtiplotrc")|' \
		${WRKSRC}/qtiplot/src/PythonScripting.cpp
.else
	@${REINPLACE_CMD} \
		-e "s/unix:SCRIPTING_LANGS += Python//" \
		${WRKSRC}/qtiplot/qtiplot.pro
.endif

.for d in ${QPRO_DIRS}
	@${REINPLACE_CMD} \
		-e "s/#system/system/g" \
		-e "s:../3rdparty/liborigin:${LOCALBASE}/include:" \
		-e "s:../3rdparty/qwt/include:${LOCALBASE}/include/qwt:" \
		-e "s:/usr/include/qwtplot3d:${X11BASE}/include:" \
		-e "/^unix:LIBS/s:-L /usr/lib:-L${LOCALBASE}/lib:" \
		-e "/^unix:documentation.path/s:/usr/share/doc/qtiplot:${DATADIR}/manual:" \
		${WRKSRC}/${d}/*.pro
.endfor
	@${REINPLACE_CMD} -e "s:3rdparty/qwt::" ${WRKSRC}/qtiplot.pro
	@${REINPLACE_CMD} -e 's:"/usr/share/doc/qtiplot:"${DOCSDIR}:' \
		${WRKSRC}/qtiplot/src/application.cpp

do-configure:
.for d in ${QPRO_DIRS}
	@cd ${WRKSRC}/${d} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${QMAKESPEC} *.pro
.endfor

post-configure:
.for d in ${QPRO_DIRS}
	@${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|-pipe||; \
		 s|^\(CFLAGS .*= \)|\1${CFLAGS}|; \
		 s|^\(CXXFLAGS = \)|\1${CXXFLAGS}|; \
		 s|../3rdparty/qwt/lib/libqwt.a|-lqwt|' \
		${WRKSRC}/${d}/Makefile
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
	${INSTALL_DATA} ${WRKSRC}/qtiplot/qtiplotrc.py ${DATADIR}/qtiplotrc.py
	@cd ${WRKSRC}/qtiplot && ${PYTHON_CMD} -c "import py_compile; py_compile.compile('qtiplotrc.py')"
	${INSTALL_DATA} ${WRKSRC}/qtiplot/qtiplotrc.pyc ${DATADIR}/qtiplotrc.pyc
.endif
.if !defined(WITHOUT_NLS)
.for i in ${QTI_LANG}
	${MKDIR} ${DATADIR}/translations/
	${INSTALL_DATA}	${WRKSRC}/qtiplot/translations/qtiplot_${i}.qm \
	${DATADIR}/translations/
.endfor
.endif

.include <bsd.port.post.mk>
