# New ports collection makefile for:	barry
# Date created: 			19 September 2002
# Whom:					Brad Davis <so14k@so14k.com>
#
# $FreeBSD$
#

PORTNAME=	barry
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.student.uni-oldenburg.de/frerich.raabe/barry/ \
		http://freebsd.so14k.com/barry/

MAINTAINER=	so14k@so14k.com
COMMENT=	A nice KDE frontend to the ports system

USE_BZIP2=	yes
USE_KDELIBS_VER=3
MAKE_ENV=	QTDIR="${X11BASE}" KDEDIR="${LOCALBASE}" PREFIX="${PREFIX}"
USE_REINPLACE=	yes

pre-build:
	${REINPLACE_CMD} "s,-pthread,${PTHREAD_LIBS},g" ${WRKSRC}/Makefile

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} .depend)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})

pre-install:
	${MKDIR} ${DESTDIR}${PREFIX}/share/applnk/Utilities

.include <bsd.port.mk>
