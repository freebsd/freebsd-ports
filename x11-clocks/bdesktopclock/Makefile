# New ports collection makefile for:	BDesktopClock
# Date created:				Sat Dec  4 11:22:12 MSK 2004
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	bdesktopclock
PORTVERSION=	1.1.2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.bucote.com/opensource/bdesktopclock/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A wondeful clock for desktop environment

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

WRKSRC=		${WRKDIR}/BDesktopClock

USE_X_PREFIX=	yes
USE_QT_VER=	3
MAKE_ENV+=	QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

PLIST_FILES=	bin/BDesktopClock

post-extract:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/BDesktopClock.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake PREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/BDesktopClock ${PREFIX}/bin

.include <bsd.port.mk>
