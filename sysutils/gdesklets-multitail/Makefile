# New ports collection makefile for:	gdesklets-multitail
# Date created:				18 November 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	multitail
PORTVERSION=	0.1.6
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	multitail-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Tail up to 5 files in one gdesklets display

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

WRKSRC=		${WRKDIR}/${NAME1}-${PORTVERSION}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes
NAME1=		MultiTail
NAME2=		DisplayConstraints

do-build:
	@${WRKSRC}/Install_${NAME1}_Sensor.bin --nomsg ${WRKSRC}
	@${WRKSRC}/Install_${NAME2}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME1}
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME2}
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Displays/${NAME1}/dark-theme/gfx
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Displays/${NAME1}/light-theme/gfx
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Displays/${NAME1}/trans-theme/gfx
	${INSTALL_DATA} ${WRKSRC}/${NAME1}/README \
		${PREFIX}/share/gnome/gdesklets/Displays/${NAME1}/
	${INSTALL_DATA} ${WRKSRC}/${NAME1}/dark-theme/*.display \
		${PREFIX}/share/gnome/gdesklets/Displays/${NAME1}/dark-theme/
	${INSTALL_DATA} ${WRKSRC}/${NAME1}/dark-theme/gfx/*.png \
		${PREFIX}/share/gnome/gdesklets/Displays/${NAME1}/dark-theme/gfx/
	${INSTALL_DATA} ${WRKSRC}/${NAME1}/light-theme/*.display \
		${PREFIX}/share/gnome/gdesklets/Displays/${NAME1}/light-theme/
	${INSTALL_DATA} ${WRKSRC}/${NAME1}/light-theme/gfx/*.png \
		${PREFIX}/share/gnome/gdesklets/Displays/${NAME1}/light-theme/gfx/
	${INSTALL_DATA} ${WRKSRC}/${NAME1}/trans-theme/*.display \
		${PREFIX}/share/gnome/gdesklets/Displays/${NAME1}/trans-theme/
	${INSTALL_DATA} ${WRKSRC}/${NAME1}/trans-theme/gfx/*.png \
		${PREFIX}/share/gnome/gdesklets/Displays/${NAME1}/trans-theme/gfx/
	${INSTALL_DATA} ${WRKSRC}/${NAME1}/*.py \
		${PREFIX}/share/gnome/gdesklets/Sensors/${NAME1}/
	${INSTALL_DATA} ${WRKSRC}/${NAME2}/*.py \
		${PREFIX}/share/gnome/gdesklets/Sensors/${NAME2}/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/gnome/gdesklets/Sensors/${NAME1}/
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/gnome/gdesklets/Sensors/${NAME1}/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/gnome/gdesklets/Sensors/${NAME2}/
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/gnome/gdesklets/Sensors/${NAME2}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
