# New ports collection makefile for:	BDesktopClock
# Date created:				Sat Dec  4 11:22:12 MSK 2004
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	bdesktopclock
PORTVERSION=	1.1.2
PORTREVISION=	6
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.bucote.com/opensource/bdesktopclock/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple clock for desktop environment

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/BDesktopClock

USE_QT_VER=	3
MAKE_ENV+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
USE_XORG=	x11 xau xcursor xdmcp xext xfixes xft xi xinerama \
		xrandr xrender xt

PLIST_FILES=	bin/BDesktopClock

post-extract:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/BDesktopClock.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake PREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/BDesktopClock ${PREFIX}/bin

.include <bsd.port.mk>
