# New ports collection makefile for:	qtiplot
# Date created:			9 May 2005
# Whom:				Jie Gao <gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	qtiplot
PORTVERSION=	0.8.5
CATEGORIES=	math science
MASTER_SITES=	http://soft.proindependent.com/src/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	An Origin clone for data analysis and scientific plotting

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	gsl.9:${PORTSDIR}/math/gsl \
		qwt:${PORTSDIR}/x11-toolkits/qwt \
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

.if exists(${X11BASE}/share/qt/mkspecs/freebsd-g++)
QMAKESPEC=	${X11BASE}/share/qt/mkspecs/freebsd-g++
.else
QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		"s:../3rdparty/qwt/include:${LOCALBASE}/include/qwt:" \
		-e "s:/usr/include/qwtplot3d:${X11BASE}/include:" \
		-e "/^unix:LIBS/s:-L /usr/lib:-L${LOCALBASE}/lib:" \
		-e "/^unix:LIBS/s:../3rdparty/qwt/lib/libqwt.a:-L ${LOCALBASE}/lib -lqwt:" \
		-e "/^unix:documentation.path/s:/usr/share/doc/qtiplot:${DOCSDIR}:" \
		${WRKSRC}/${PORTNAME}.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${QMAKESPEC} ${PORTNAME}.pro

post-configure:
	@${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|-pipe||; \
		 s|^\(CFLAGS .*= \)|\1${CFLAGS}|; \
		 s|^\(CXXFLAGS = \)|\1${CXXFLAGS}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtiplot/qtiplot ${PREFIX}/bin
#.if !defined(NOPORTDOCS)
#	${MKDIR} ${DOCSDIR}
#.for DOCFN in ${PORTDOCS}
#	${INSTALL_MAN} ${WRKSRC}/doc/${DOCFN} ${DOCSDIR}
#.endfor
#.endif

.include <bsd.port.post.mk>
