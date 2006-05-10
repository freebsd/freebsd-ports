# ex:ts=8
# Ports collection makefile for:	qgfe
# Date created:			Aug 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qgfe
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	http://www.xm1math.net/qgfe/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnuplot Front End

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_BZIP2=	yes
USE_QT_VER=	3
MAKE_ENV=	QTDIR=${X11BASE} \
		MOC=${MOC}

PLIST_FILES=	bin/qgfe

pre-build:
	@cd ${WRKSRC}; qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ ${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qgfe ${PREFIX}/bin

.include <bsd.port.mk>
