# New ports collection makefile for:	gdesklets-multitail
# Date created:				18 November 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	multitail
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	gDesklets-multitail-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Displays multiple log files in one gDesklets display

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_X_PREFIX=	yes
USE_PYTHON=	yes
DATADIR=	${PREFIX}/share/gnome
NAME=		MultiTail
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${NAME}

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx/dark
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx/light
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${NAME}/README \
		${DATADIR}/gdesklets/Displays/${NAME}/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.display \
		${DATADIR}/gdesklets/Displays/${NAME}/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/gfx/dark/*.png \
		${DATADIR}/gdesklets/Displays/${NAME}/gfx/dark/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/gfx/light/*.png \
		${DATADIR}/gdesklets/Displays/${NAME}/gfx/light/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/gfx/*.png \
		${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py \
		${DATADIR}/gdesklets/Sensors/${NAME}/
	${INSTALL_DATA} ${WRKSRC}/${NAME}/sample.multitail \
		${EXAMPLESDIR}/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${DATADIR}/gdesklets/Sensors/${NAME}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
