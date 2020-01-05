# Created by: Philip Paeps <philip@paeps.cx>
# $FreeBSD$

PORTNAME=	gtk-cleanice-engine
PORTVERSION=	2.4.1
PORTREVISION=	7
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/elysium-project/gtk-engines-cleanice/${PORTVERSION} \
		SF/elysium-project/gtk-engines-cleanice/1.2.7:theme
DISTNAME=	gtk-engines-cleanice-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${THEME}${EXTRACT_SUFX}:theme

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simplistic GTK+ 2.x theme engine

BROKEN=		unfetchable

USES=		gnome libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
INSTALL_TARGET=	install-strip

THEME=		cleanice-theme-1.2.7
THEMEDIR=	${WRKDIR}/${THEME}/Theme

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/CleanIce
	${INSTALL_DATA} ${THEMEDIR}/cleanice/index.theme \
		${STAGEDIR}${PREFIX}/share/themes/CleanIce
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/CleanIce/gtk-2.0
	${INSTALL_DATA} ${THEMEDIR}/cleanice/gtkrc \
		${STAGEDIR}${PREFIX}/share/themes/CleanIce/gtk-2.0
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/CleanIce/metacity-1
	${INSTALL_DATA} ${THEMEDIR}/cleanice/metacity-theme-1.xml \
		${STAGEDIR}${PREFIX}/share/themes/CleanIce/metacity-1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/CleanIce-Dark/gtk-2.0
	${INSTALL_DATA} ${THEMEDIR}/cleanice-dark/gtkrc \
		${STAGEDIR}${PREFIX}/share/themes/CleanIce-Dark/gtk-2.0

.include <bsd.port.mk>
