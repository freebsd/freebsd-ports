# New ports collection makefile for:	gdesklets-sysinfo
# Date created:				13 November 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	sysinfo
PORTVERSION=	0.21.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	SysInfo-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	klammer@webonaut.com
COMMENT=	Desklet shows various information about your system

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

# XXX Note, this file is a gzip file with a .bz2 extension.
#USE_BZIP2=	yes
USE_X_PREFIX=	yes
NAME=		SysInfo
WRKSRC=		${WRKDIR}/${NAME}

post-extract:
	@${MV} ${WRKDIR}/Install_${NAME}_Sensor.bin ${WRKSRC}/

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${PATCH} -d ${WRKDIR} -sp0 < ${PATCHDIR}/postbuild-patch-__init__.py
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/gfx
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}/gfx
	@${INSTALL_DATA} ${WRKSRC}/*.display ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/gfx/*.png ${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}/gfx/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
