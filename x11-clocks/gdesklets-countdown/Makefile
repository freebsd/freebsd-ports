# New ports collection makefile for:	gdesklets-countdown
# Date created:				06 January 2004
# Whom:					Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	countdown
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	x11-clocks gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	Countdown-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Countdown the remaining time until a configurable date

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes

NAME=		Countdown
DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${WRKSRC}/Install_LTVFontSelector_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/LTVFontSelector/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/LTVFontSelector/*.py ${DATADIR}/gdesklets/Sensors/LTVFontSelector/
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Displays/${NAME}/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/LTVFontSelector
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/LTVFontSelector
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
