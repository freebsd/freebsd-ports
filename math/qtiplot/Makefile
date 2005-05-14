# New ports collection makefile for:	qtiplot
# Date created:			9 May 2005
# Whom:				Jie Gao <gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	qtiplot
PORTVERSION=	0.6.0
CATEGORIES=	math science
MASTER_SITES=	http://soft.proindependent.com/

MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	An Origin clone for data analysis and scientific plotting

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl \
		qwt:${PORTSDIR}/x11-toolkits/qwt \
		qwtplot3d:${PORTSDIR}/math/qwtplot3d

USE_ZIP=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/qtiplot

USE_QT_VER=	3
MAKE_ENV=	QTDIR=${QT_PREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on FreeBSD 4.x
.endif

pre-configure:
	@${REINPLACE_CMD} -e \
		"s:/home/ion/qt/qwt-4.2.0/include:${LOCALBASE}/include/qwt:" \
		-e "s:/home/ion/qt/qwtplot3d/include:${X11BASE}/include:" \
		-e "/^unix:LIBS/s:-L /usr/lib:-L${LOCALBASE}/lib:" \
		${WRKSRC}/qtiplot.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec freebsd-g++ qtiplot.pro

post-configure:
	@${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|-pipe||; \
		 s|^\(CFLAGS .*= \)|\1${CFLAGS}|; \
		 s|^\(CXXFLAGS = \)|\1${CXXFLAGS}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtiplot ${PREFIX}/bin

.include <bsd.port.post.mk>
