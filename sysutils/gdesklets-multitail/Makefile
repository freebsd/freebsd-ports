# New ports collection makefile for:	gdesklets-multitail
# Date created:				18 November 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	multitail
PORTVERSION=	0.1.6
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	multitail-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Tail up to 5 files in one gdesklets display

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets \
		${DATADIR}/gdesklets/Sensors/DisplayConstraints/__init__.py:${PORTSDIR}/deskutils/gdesklets-sensor-displayconstraints

WRKSRC=		${WRKDIR}/${NAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes
DATADIR=	${PREFIX}/share/gnome
NAME=		MultiTail

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/dark-theme/gfx
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/light-theme/gfx
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/trans-theme/gfx
	${INSTALL_DATA} ${WRKSRC}/${NAME}/README \
		${DATADIR}/gdesklets/Displays/${NAME}/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/dark-theme/*.display \
		${DATADIR}/gdesklets/Displays/${NAME}/dark-theme/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/dark-theme/gfx/*.png \
		${DATADIR}/gdesklets/Displays/${NAME}/dark-theme/gfx/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/light-theme/*.display \
		${DATADIR}/gdesklets/Displays/${NAME}/light-theme/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/light-theme/gfx/*.png \
		${DATADIR}/gdesklets/Displays/${NAME}/light-theme/gfx/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/trans-theme/*.display \
		${DATADIR}/gdesklets/Displays/${NAME}/trans-theme/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/trans-theme/gfx/*.png \
		${DATADIR}/gdesklets/Displays/${NAME}/trans-theme/gfx/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py \
		${DATADIR}/gdesklets/Sensors/${NAME}/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${DATADIR}/gdesklets/Sensors/${NAME}/
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${DATADIR}/gdesklets/Sensors/${NAME}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
