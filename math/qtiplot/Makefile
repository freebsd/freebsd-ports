# New ports collection makefile for:	qtiplot
# Date created:			9 May 2005
# Whom:				Jie Gao <gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	qtiplot
PORTVERSION=	0.8.6.2
CATEGORIES=	math science
MASTER_SITES=	http://soft.proindependent.com/src/
DISTNAME=	${PORTNAME}-0.8.6-2

MAINTAINER=	makc@issp.ac.ru
COMMENT=	An Origin clone for data analysis and scientific plotting

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	gsl.9:${PORTSDIR}/math/gsl \
		origin.0:${PORTSDIR}/math/liborigin \
		qwtplot3d:${PORTSDIR}/math/qwtplot3d

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/qtiplot
#PORTDOCS=	faq.html help.html

USE_QT_VER=	3
MAKE_ENV=	QTDIR=${QT_PREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on FreeBSD 4.x
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
		-e "/^unix:documentation.path/s:/usr/share/doc/qtiplot:${DOCSDIR}:" \
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
	${INSTALL_PROGRAM} ${WRKSRC}/qtiplot/qtiplot ${PREFIX}/bin
#.if !defined(NOPORTDOCS)
#	${MKDIR} ${DOCSDIR}
#.for DOCFN in ${PORTDOCS}
#	${INSTALL_MAN} ${WRKSRC}/doc/${DOCFN} ${DOCSDIR}
#.endfor
#.endif

.include <bsd.port.post.mk>
