# New ports collection makefile for:	clearlooks-themes-extras
# Date created:				10 April 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clearlooks-themes-extras
PORTVERSION=	0.5.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kernow-webhosting.com/~bvc/theme/gtk/clearlooks/0.5/
DISTNAME=	Clearlooks-Big_Pack-${PORTVERSION}

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Extras colour schemes for Clearlooks engine theme

RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/2.4.0/engines/libclearlooks.so:${PORTSDIR}/x11-themes/clearlooks

NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

THEME_DIR=	${PREFIX}/share/themes
GTKRC=		Clearlooks-3.1-Ergo Clearlooks-4Humans Clearlooks-Ana \
		Clearlooks-Bluey Clearlooks-Coffee Clearlooks-Decaf_Coffee \
		Clearlooks-DeepSkyM Clearlooks-Etiquette Clearlooks-Gartoon \
		Clearlooks-Glider Clearlooks-Gull Clearlooks-Lila \
		Clearlooks-Lucidity Clearlooks-Mask Clearlooks-Milk \
		Clearlooks-Nuvola Clearlooks-OliveM Clearlooks-Pastel \
		Clearlooks-Phacile_blue Clearlooks-Serenity Clearlooks-Ubuntu \
		Clearlooks-gOrangeous ClearlooksM
ICONS=		Clearlooks-Ana Clearlooks-Bluey Clearlooks-Etiquette \
		Clearlooks-Lila Clearlooks-Milk Clearlooks-Nuvola

post-patch:
	@${REINPLACE_CMD} -e 's|iconrc|icons/iconrc|g' \
		${WRKSRC}/Clearlooks-Glider/gtk-2.0/gtkrc
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*~' -delete

do-install:
.for g in ${GTKRC}
	@${MKDIR} ${THEME_DIR}/${g}/gtk-2.0
	@${INSTALL_DATA} ${WRKSRC}/${g}/gtk-2.0/gtkrc \
		${THEME_DIR}/${g}/gtk-2.0/
.endfor
.for i in ${ICONS}
	@${MKDIR} ${THEME_DIR}/${i}/gtk-2.0/icons/
	@${INSTALL_DATA} ${WRKSRC}/${i}/gtk-2.0/icons/* \
		${THEME_DIR}/${i}/gtk-2.0/icons/
.endfor
	@${MKDIR} ${THEME_DIR}/Clearlooks-Gartoon/gtk-2.0/icons/Xtra
	@${INSTALL_DATA} ${WRKSRC}/Clearlooks-Gartoon/gtk-2.0/icons/iconrc \
		${THEME_DIR}/Clearlooks-Gartoon/gtk-2.0/icons/
	@${INSTALL_DATA} ${WRKSRC}/Clearlooks-Gartoon/gtk-2.0/icons/*.svg \
		${THEME_DIR}/Clearlooks-Gartoon/gtk-2.0/icons/
	@${INSTALL_DATA} ${WRKSRC}/Clearlooks-Gartoon/gtk-2.0/icons/Xtra/* \
		${THEME_DIR}/Clearlooks-Gartoon/gtk-2.0/icons/Xtra/
	@${MKDIR} ${THEME_DIR}/Clearlooks-Glider/gtk-2.0/icons
	@${INSTALL_DATA} ${WRKSRC}/Clearlooks-Glider/gtk-2.0/iconrc \
		${THEME_DIR}/Clearlooks-Glider/gtk-2.0/icons/
	@${INSTALL_DATA} ${WRKSRC}/Clearlooks-Glider/gtk-2.0/*.png \
		${THEME_DIR}/Clearlooks-Glider/gtk-2.0/icons/
	@${MKDIR} ${THEME_DIR}/Clearlooks-gOrangeous/gtk-2.0/icons/Xtra
	@${INSTALL_DATA} ${WRKSRC}/Clearlooks-gOrangeous/gtk-2.0/icons/iconrc \
		${THEME_DIR}/Clearlooks-gOrangeous/gtk-2.0/icons/
	@${INSTALL_DATA} ${WRKSRC}/Clearlooks-gOrangeous/gtk-2.0/icons/*.svg \
		${THEME_DIR}/Clearlooks-gOrangeous/gtk-2.0/icons/
	@${INSTALL_DATA} ${WRKSRC}/Clearlooks-gOrangeous/gtk-2.0/icons/Xtra/* \
		${THEME_DIR}/Clearlooks-gOrangeous/gtk-2.0/icons/Xtra/

.include <bsd.port.mk>
