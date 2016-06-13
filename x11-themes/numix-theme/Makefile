# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	numix
PORTVERSION=	2.6.0
CATEGORIES=	x11-themes xfce
PKGNAMESUFFIX=	-theme

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Gtk flat themes

LICENSE=	GPLv3

BUILD_DEPENDS=	rubygem-sass>=3.3.4:textproc/rubygem-sass
RUN_DEPENDS=	gtk-murrine-engine>=0.98.2:x11-themes/gtk-murrine-engine

GH_ACCOUNT=	numixproject
GH_PROJECT=	numix-gtk-theme

USE_GITHUB=	yes
USES=	gmake
USE_GNOME=	glib20 gdkpixbuf2
INSTALL_TARGET=	# empty

OPTIONS_DEFINE=	NOTIFYD
OPTIONS_DEFAULT=	NOTIFYD
NOTIFYD_DESC=	Install xfce4-notifyd theme
OPTIONS_SUB=	yes

post-patch:
# Remove .orig files
	@${RM} ${WRKSRC}/gtk-?.0/*.orig

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Numix
.for dir in gtk-2.0 gtk-3.0 gtk-3.20 metacity-1 openbox-3 xfwm4
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${dir} \
		${STAGEDIR}${PREFIX}/share/themes/Numix \
		"! -path *scss*"
.endfor

do-install-NOTIFYD-on:
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} xfce-notify-4.0 \
		${STAGEDIR}${PREFIX}/share/themes/Numix

.include <bsd.port.mk>
