# New ports collection makefile for:	kseg
# Date created:		4 September 2001
# Whom:			Kuang-che Wu <kcwu@ck.tp.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	kseg
PORTVERSION=	0.403
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	math graphics
MASTER_SITES=	http://www.mit.edu/~ibaran/

MAINTAINER=	kcwu@csie.org
COMMENT=	A simulator of euclidean geometry

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_QT_VER=	3
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS} QTDIR="${QT_PREFIX}"

pre-patch:
	${REINPLACE_CMD} -e '/^CONFIG/s/$$/ thread/' ${WRKSRC}/${PORTNAME}.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
	-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ ${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kseg ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/X11/kseg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/lib/X11/kseg
	${INSTALL_DATA} ${WRKSRC}/kseg_??.qm ${PREFIX}/lib/X11/kseg
	${RM} ${PREFIX}/lib/X11/kseg/kseg_xx.qm
	${INSTALL_DATA} ${WRKSRC}/kseg_help_??.html ${PREFIX}/lib/X11/kseg
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
