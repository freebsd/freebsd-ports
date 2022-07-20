PORTNAME=	nordic-theme
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
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

OPTIONS_DEFINE=		CINNAMON GNOMESHELL KDE METACITY XFCE
OPTIONS_DEFAULT=	CINNAMON GNOMESHELL KDE METACITY XFCE
OPTIONS_SUB=		yes

CINNAMON_DESC=		Install Cinnamon theme
GNOMESHELL_DESC=	Install Gnome-Shell theme
KDE_DESC=		Install KDE theme
METACITY_DESC=		Install Metacity theme
XFCE_DESC=		Install XFCE theme

CINNAMON_IMPLIES=	METACITY
CINNAMON_VARS=		THEME_SUBSETS+=cinnamon
GNOMESHELL_VARS=	THEME_SUBSETS+=gnome-shell
METACITY_VARS=		THEME_SUBSETS+=metacity-1
XFCE_VARS=		THEME_SUBSETS+=xfwm4

THEMEDIR=	${PREFIX}/share/themes/Nordic
THEME_SUBSETS=	assets gtk-2.0 gtk-3.0 index.theme

post-patch:
	${RM} ${WRKSRC}/gtk-2.0/render-assets.sh
.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${THEMEDIR}
.for i in ${THEME_SUBSETS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${THEMEDIR})
.endfor

do-install-KDE-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/aurorae/themes
	(cd ${WRKSRC}/kde/aurorae && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/aurorae/themes)
	(cd ${WRKSRC}/kde/colorschemes/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/color-schemes)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/konsole
	(cd ${WRKSRC}/kde/konsole/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/konsole)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Kvantum
	(cd ${WRKSRC}/kde/kvantum && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/Kvantum)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/plasma/look-and-feel/Nordic
	(cd ${WRKSRC}/kde/plasma/look-and-feel && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/plasma/look-and-feel/)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/sddm/themes/Nordic
	(cd ${WRKSRC}/kde/sddm/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/sddm/themes/Nordic)
.include <bsd.port.mk>
