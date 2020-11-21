# Created by: Alexander Vereeken <Alexander88207@protonmail.com>
# $FreeBSD$

PORTNAME=	nordic-theme
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Dark GTK & KDE theme created using the Nord color palette

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	EliverLara
GH_PROJECT=	Nordic
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	CINNAMON GNOMESHELL KDE METACITY XFCE
OPTIONS_DEFAULT=	GNOMESHELL KDE METACITY XFCE
OPTIONS_SUB=	yes

CINNAMON_DESC=	Install Cinnamon theme
CINNAMON_BROKEN=	This version of the theme dont have the cinnamon theme yet.
CINNAMON_IMPLIES=	METACITY

GNOMESHELL_DESC=	Install Gnome-Shell theme
KDE_DESC=	Install KDE theme
METACITY_DESC=	Install Metacity theme
XFCE_DESC=	Install XFCE theme

do-install-CINNAMON-on:
	${MV} ${WRKSRC}/cinnamon ${STAGEDIR}${PREFIX}/share/themes/Nordic/

do-install-GNOMESHELL-on:
	${MV} ${WRKSRC}/gnome-shell ${STAGEDIR}${PREFIX}/share/themes/Nordic/

do-install-METACITY-on:
	${MV} ${WRKSRC}/metacity-1 ${STAGEDIR}${PREFIX}/share/themes/Nordic/

do-install-XFCE-on:
	${MV} ${WRKSRC}/xfwm4 ${STAGEDIR}${PREFIX}/share/themes/Nordic/

do-install-KDE-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/aurorae/themes
	(cd ${WRKSRC}/kde/aurorae && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/aurorae/themes)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/color-schemes
	(cd ${WRKSRC}/kde/colorschemes/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/color-schemes)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/konsole
	(cd ${WRKSRC}/kde/konsole/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/konsole)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Kvantum
	(cd ${WRKSRC}/kde/kvantum && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/Kvantum)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/plasma/look-and-feel/Nordic
	(cd ${WRKSRC}/kde/look-and-feel && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/plasma/look-and-feel/Nordic)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/sddm/themes/Nordic
	(cd ${WRKSRC}/kde/sddm/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/sddm/themes/Nordic)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Nordic
	@${MV} ${WRKSRC}/assets ${STAGEDIR}${PREFIX}/share/themes/Nordic/
	@${MV} ${WRKSRC}/gtk-2.0 ${STAGEDIR}${PREFIX}/share/themes/Nordic/
	@${MV} ${WRKSRC}/gtk-3.0 ${STAGEDIR}${PREFIX}/share/themes/Nordic/
	@${MV} ${WRKSRC}/index.theme ${STAGEDIR}${PREFIX}/share/themes/Nordic/
	@${RM}	${STAGEDIR}${PREFIX}/share/themes/Nordic/gtk-2.0/render-assets.sh
.include <bsd.port.mk>
