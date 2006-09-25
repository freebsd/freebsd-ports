# New ports collection makefile for:	qtiplot
# Date created:			9 May 2005
# Whom:				Jie Gao <gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	qtiplot
PORTVERSION=	0.8.7.3
CATEGORIES=	math science
MASTER_SITES=	http://soft.proindependent.com/src/
DISTNAME=	${PORTNAME}-0.8.7-3

MAINTAINER=	makc@issp.ac.ru
COMMENT=	An Origin clone for data analysis and scientific plotting

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake \
		sip:${PORTSDIR}/devel/py-sip \
		pylupdate:${PORTSDIR}/x11-toolkits/py-qt
LIB_DEPENDS=	gsl.9:${PORTSDIR}/math/gsl \
		origin.0:${PORTSDIR}/math/liborigin \
		qwtplot3d:${PORTSDIR}/math/qwtplot3d
RUN_DEPENDS=	pylupdate:${PORTSDIR}/x11-toolkits/py-qt

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	2.4

USE_DOS2UNIX=	qtiplot/src/application.cpp

USE_QT_VER=	3
MAKE_ENV=	QTDIR=${QT_PREFIX}

OPTIONS=	DOCS "Install the QtiPlot Handbook" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on FreeBSD 4.x
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
		3rdparty/qwt \
		fitPlugins/fitRational0 \
		fitPlugins/fitRational1 \
		qtiplot

post-patch:
.for d in ${QPRO_DIRS}
	@${REINPLACE_CMD} -e \
		"s:../3rdparty/liborigin/include:${LOCALBASE}/include:" \
		-e "s:/usr/include/qwtplot3d:${X11BASE}/include:" \
		-e "/^unix:LIBS/s:-L /usr/lib:-L${LOCALBASE}/lib:" \
		-e "/^unix:documentation.path/s:/usr/share/doc/qtiplot:${DATADIR}/manual:" \
		-e "s:/usr/include/python2.4:/usr/local/include/python2.4:" \
		-e "s:/usr/share/sip:/usr/local/share/py-sip/:" \
		${WRKSRC}/${d}/*.pro
.endfor

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
		 s|^\(CXXFLAGS = \)|\1${CXXFLAGS}|' \
		${WRKSRC}/${d}/Makefile
.endfor

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/qtiplot/qtiplot ${DATADIR}/qtiplot
	${LN} -fs ${DATADIR}/qtiplot ${PREFIX}/bin/qtiplot
	${INSTALL_DATA} ${WRKSRC}/qtiplot/qtiplotrc.py ${DATADIR}/qtiplotrc.py
.if !defined(WITHOUT_NLS)
.for i in ${QTI_LANG}
	${MKDIR} ${DATADIR}/translations/
	${INSTALL_DATA}	${WRKSRC}/qtiplot/translations/qtiplot_${i}.qm \
	${DATADIR}/translations/
.endfor
.endif

.include <bsd.port.post.mk>
