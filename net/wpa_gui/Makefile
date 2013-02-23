# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD$

PORTNAME=	wpa_gui
PORTVERSION=	0.5.11
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://hostap.epitest.fi/releases/
DISTNAME=	wpa_supplicant-${PORTVERSION}

MAINTAINER=	webmaster@kibab.com
COMMENT=	Qt-based frontend for wpa_supplicant

PLIST_FILES=	sbin/${PORTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/wpa_gui-qt4
USE_QT4=	gui qt3support qmake_build moc_build uic_build
QMAKE_ARGS+=	PREFIX=${PREFIX}
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES=	"${PORTNAME}" "Frontend for WPA Supplicant" "" \
			"${PORTNAME}" "System;Qt;" "true"

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin

.include <bsd.port.mk>
