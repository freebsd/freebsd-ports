# New ports collection makefile for:	gdesklets-sysinfo
# Date created:				13 November 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	sysinfo
PORTVERSION=	0.23
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	SysInfo-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Desklet shows various information about your system

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NAME=		SysInfo
DATADIR=	${PREFIX}/share/gnome
LANG=		de es fr pt sq sr sr@Latn sv
PKGMESSAGE=	${WRKDIR}/pkg-message

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${PATCH} -d ${WRKDIR} -sp0 < ${PATCHDIR}/postbuild-patch-__init__.py
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}/gfx
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/__init__.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/gfx/*.png ${DATADIR}/gdesklets/Sensors/${NAME}/gfx/
.for ii in ${LANG}
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}/locale/${ii}/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/locale/${ii}/LC_MESSAGES/*.mo \
		${DATADIR}/gdesklets/Sensors/${NAME}/locale/${ii}/LC_MESSAGES/
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
