# Created by: okeeblow <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	aurora
PORTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	http://gnome-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine
DISTNAME=	56438-aurora-1.5.1

MAINTAINER=	root@cooltrainer.org
COMMENT=	Aurora GTK+ 2.x engine and "Aurora" theme

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2

USES=		gmake pkgconfig
USE_BZIP2=	yes
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/engines
	${INSTALL_DATA} ${WRKSRC}/libaurora.la ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/engines
	${INSTALL_DATA} ${WRKSRC}/.libs/libaurora.so ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Aurora/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Aurora/gtk-2.0/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/gtk-2.0/gtkrc ${STAGEDIR}${PREFIX}/share/themes/Aurora/gtk-2.0/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/close.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/close_prelight.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/close_prelight_glow.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/close_small.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/close_small_prelight.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/maximize.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/maximize_prelight.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/menu.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/menu_prelight.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/menu_small.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/menu_small_prelight.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/metacity-theme-1.xml ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/metacity-theme-2.xml ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/minimize.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/minimize_prelight.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/restore.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/
	${INSTALL_DATA} ${WRKDIR}/Aurora/metacity-1/restore_prelight.png ${STAGEDIR}${PREFIX}/share/themes/Aurora/metacity-1/

.include <bsd.port.mk>
