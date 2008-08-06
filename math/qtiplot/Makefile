# New ports collection makefile for:	qtiplot
# Date created:			9 May 2005
# Whom:				Jie Gao <gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	qtiplot
DISTVERSION=	0.9.7
CATEGORIES=	math science
MASTER_SITES=	BERLIOS http://soft.proindependent.com/src/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	An Origin clone for data analysis and scientific plotting

BUILD_DEPENDS=	${LOCALBASE}/lib/libmuparser.a:${PORTSDIR}/math/muparser
LIB_DEPENDS=	gsl.12:${PORTSDIR}/math/gsl \
		qwtplot3d-qt4:${PORTSDIR}/math/qwtplot3d-qt4 \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build opengl svg qt3support network assistantclient
HAS_CONFIGURE=	yes
QMAKE_ARGS+=	-unix -recursive LOCALBASE=${LOCALBASE} PYTHON_CMD=${PYTHON_CMD}
USE_DOS2UNIX=	*.pro
MAN1=		qtiplot.1

DESKTOP_ENTRIES="QtiPlot" "Data analysis and plotting" \
		"${DATADIR}/qtiplot.png" \
		"qtiplot" "" false

OPTIONS=	DOCS "Install the QtiPlot Handbook" on \
		PYTHON "Python scripting support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
# manually include this, because USE_PYTHON is defined
# after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.python.mk"
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
.endif

.if !defined(WITHOUT_NLS)
QT_COMPONENTS+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if defined(WITH_PYTHON)
	@${REINPLACE_CMD} -e \
		'/^sys.path.append/s|"\."|"${DATADIR}"|' \
		${WRKSRC}/${PORTNAME}/qtiplotrc.py
	@${REINPLACE_CMD} -e \
		"/^#SCRIPTING_LANGS.*Python/s|^#||" \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.else
	@${REINPLACE_CMD} -e \
		"s/^SCRIPTING_LANGS.*Python//" \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.endif
	@${REINPLACE_CMD} -e \
		's|/usr/lib/qtiplot/plugins|${DATADIR}/fitPlugins|' \
		${WRKSRC}/qtiplot/src/ApplicationWindow.cpp
	@${REINPLACE_CMD} -e '/^system(lupdate/d; /^system(lrelease/d' \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.if defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e \
		"/^CONFIG.*release/s|release|debug|" \
		${WRKSRC}/${PORTNAME}/qtiplot.pro
.endif

do-configure:
.if !defined(WITHOUT_NLS)
	@(cd ${WRKSRC}/qtiplot && ${LOCALBASE}/bin/lrelease-qt4 qtiplot.pro)
.endif
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS})

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|; s|^LINK .*|LINK=${CXX}|'
	@${REINPLACE_CMD} -e 's|^\(INCPATH.*=\)|\1-I../3rdparty/liborigin|' ${WRKSRC}/qtiplot/Makefile

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/qtiplot/qtiplot ${DATADIR}/qtiplot
	${LN} -fs ${DATADIR}/qtiplot ${PREFIX}/bin/qtiplot
	${INSTALL_MAN} ${WRKSRC}/qtiplot.1 ${PREFIX}/man/man1
	${MKDIR} ${DATADIR}/fitPlugins
	${INSTALL_PROGRAM} ${WRKSRC}/fitPlugins/libfitRational0.so.1.0.0 \
				${DATADIR}/fitPlugins/libfitRational0.so
	${INSTALL_PROGRAM} ${WRKSRC}/fitPlugins/libfitRational1.so.1.0.0 \
				${DATADIR}/fitPlugins/libfitRational1.so
	${INSTALL_DATA} ${WRKSRC}/qtiplot_logo.png ${DATADIR}/qtiplot.png
	${INSTALL_DATA} ${WRKSRC}/qtiplot/qti_wordlist.txt ${DATADIR}
.if defined(WITH_PYTHON)
.for s in qtiplotrc.py qtiUtil.py
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${s} ${DATADIR}/${s}
	@(cd ${WRKSRC}/qtiplot && ${PYTHON_CMD} -c "import py_compile; py_compile.compile('${s}')")
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${s}c ${DATADIR}/${s}c
.endfor
.endif
.if !defined(WITHOUT_NLS)
	@(cd ${WRKSRC}/qtiplot/translations/ && ${COPYTREE_SHARE} '*.qm' ${DATADIR}/translations)
.endif

.include <bsd.port.post.mk>
