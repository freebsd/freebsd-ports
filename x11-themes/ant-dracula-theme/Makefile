# Created by: Alexander Vereeken <Alexander88207@protonmail.com>

PORTNAME=	ant-dracula-theme
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Dark theme for GTK & KDE

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	dracula
GH_PROJECT=	gtk
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=		CINNAMON GNOMESHELL KDE METACITY XFCE
OPTIONS_DEFAULT=	CINNAMON GNOMESHELL KDE METACITY XFCE
OPTIONS_SUB=		yes

CINNAMON_DESC=		Install Cinnamon theme
CINNAMON_IMPLIES=	METACITY
CINNAMON_VARS=		THEME_SUBSETS+=cinnamon

GNOMESHELL_DESC=	Install Gnome-Shell theme
GNOMESHELL_VARS=	THEME_SUBSETS+=gnome-shell

KDE_DESC=	Install KDE theme

METACITY_DESC=	Install Metacity theme
METACITY_VARS=	THEME_SUBSETS+=metacity-1

XFCE_DESC=	Install XFCE theme
XFCE_VARS=	THEME_SUBSETS+=xfwm4

THEMEDIR=	${PREFIX}/share/themes/Ant-Dracula
THEME_SUBSETS=	assets gtk-2.0 gtk-3.0 gtk-3.20 gtk-4.0 index.theme

post-patch:
	${RM} ${WRKSRC}/gtk-2.0/render-assets.sh \
		${WRKSRC}/gtk-3.20/assets/render-gtk3-assets-hidpi.py \
		${WRKSRC}/gtk-3.20/assets/render-gtk3-assets.py \
		${WRKSRC}/gtk-4.0/assets/render-gtk3-assets-hidpi.py \
		${WRKSRC}/gtk-4.0/assets/render-gtk3-assets.py

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${THEMEDIR}
.for i in ${THEME_SUBSETS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${THEMEDIR})
.endfor

do-install-KDE-on:
	(cd ${WRKSRC}/kde && ${COPYTREE_SHARE} color-schemes ${STAGEDIR}${PREFIX}/share)
	(cd ${WRKSRC}/kde && ${COPYTREE_SHARE} plasma ${STAGEDIR}${PREFIX}/share)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/aurorae/themes
	(cd ${WRKSRC}/kde/aurorae && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/aurorae/themes)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Kvantum
	(cd ${WRKSRC}/kde/kvantum && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/Kvantum)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/sddm/themes
	(cd ${WRKSRC}/kde/sddm && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/sddm/themes)

.include <bsd.port.mk>
