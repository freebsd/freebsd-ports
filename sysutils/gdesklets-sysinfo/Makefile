# New ports collection makefile for:	gdesklets-sysinfo
# Date created:				13 November 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	sysinfo
PORTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	SysInfo-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Desklet shows various information about your system

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

USE_X_PREFIX=	yes
USE_PYTHON=	yes
NAME=		SysInfo
DATADIR=	${PREFIX}/share/gnome
LANG=		de es fr pt sq sr sr@Latn sv
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${NAME}
IGNORE=		Seems to be a dead Project - Do not run with gDesklets 0.34.x.

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${PATCH} -d ${WRKSRC} -sp0 < ${PATCHDIR}/postbuild-patch-SysInfo.py
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}
.for ii in ${LANG}
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}/locale/${ii}/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/locale/${ii}/LC_MESSAGES/gdesklets.mo \
		${DATADIR}/gdesklets/Sensors/${NAME}/locale/${ii}/LC_MESSAGES/sysinfo-sensor.mo
.endfor

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
