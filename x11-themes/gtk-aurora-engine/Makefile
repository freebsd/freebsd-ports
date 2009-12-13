# New ports collection makefile for:	gtk-aurora-engine
# Date created:		2009-12-03
# Whom:			okeeblow <root@cooltrainer.org>
#
# $FreeBSD$
#

PORTNAME=	aurora
PORTVERSION=	1.5.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://gnome-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine
DISTNAME=	56438-aurora-1.5.1

MAINTAINER=	root@cooltrainer.org
COMMENT=	Aurora GTK+ 2.x engine and "Aurora" theme

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/aurora-1.5

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKDIR}
	@cd ${WRKDIR} && ${TAR} jxf ${DISTFILES} && ${RM} -f ${DISTFILES}
	@cd ${WRKDIR} && ${TAR} zxf aurora-gtk-engine-1.5.tar.gz && ${RM} -f aurora-gtk-engine-1.5.tar.gz
	@cd ${WRKDIR} && ${TAR} jxf Aurora.tar.bz2 && ${RM} -f Aurora.tar.bz2

do-install:
	@${MKDIR} ${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/engines
	${INSTALL_DATA} ${WRKSRC}/libaurora.la ${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/engines
	${INSTALL_DATA} ${WRKSRC}/.libs/libaurora.so ${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/engines
	@${MKDIR} ${PREFIX}/share/
	@${MKDIR} ${PREFIX}/share/themes/
	@${MKDIR} ${PREFIX}/share/themes/Aurora/
	@${MKDIR} ${PREFIX}/share/themes/Aurora/gtk-2.0/
	@${MKDIR} ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/gtk-2.0/gtkrc ${PREFIX}/share/themes/Aurora/gtk-2.0/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/close.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/close_prelight.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/close_prelight_glow.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/close_small.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/close_small_prelight.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/maximize.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/maximize_prelight.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/menu.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/menu_prelight.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/menu_small.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/menu_small_prelight.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/metacity-theme-1.xml ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/metacity-theme-2.xml ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/minimize.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/minimize_prelight.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/restore.png ${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/restore_prelight.png ${PREFIX}/share/themes/Aurora/metacity-1/

.include <bsd.port.mk>
