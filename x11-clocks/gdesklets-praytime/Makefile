# New ports collection makefile for:	gdesklets-praytime
# Date created:				06 January 2004
# Whom:					Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	praytime
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	x11-clocks gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	${PORTNAME}-desklet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display muslim prayer times on your desktop

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes

NAME=		PrayerTime
DATADIR=	${PREFIX}/share/gnome
WRKSRC=		${WRKDIR}/${PORTNAME}-desklet-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${NAME}|g' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/icons
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/icons/*.png ${DATADIR}/gdesklets/Displays/${NAME}/icons/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Displays/${NAME}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
