# Created by: Olivier Duchateau

PORTNAME=	numix-gtk-theme
PORTVERSION=	2.6.7
PORTREVISION=	1
CATEGORIES=	x11-themes xfce

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk flat themes

LICENSE=	GPLv3

BUILD_DEPENDS=	rubygem-sass>=3.4:textproc/rubygem-sass
RUN_DEPENDS=	gtk-murrine-engine>=0.98.2:x11-themes/gtk-murrine-engine

USES=		gmake gnome

USE_GITHUB=	yes
GH_ACCOUNT=	numixproject

USE_GNOME=	glib20 gdkpixbuf2

INSTALL_TARGET=	# empty

NO_ARCH=	yes

OPTIONS_DEFINE=	NOTIFYD
OPTIONS_DEFAULT=	NOTIFYD
OPTIONS_SUB=	yes

NOTIFYD_DESC=	Install xfce4-notifyd theme

post-patch:
# Remove .orig files
	@${RM} ${WRKSRC}/src/gtk-?.0/*.orig

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Numix
.for dir in assets gtk-2.0 gtk-3.0 gtk-3.20 metacity-1 openbox-3 xfwm4
	@cd ${WRKSRC}/src && \
		${COPYTREE_SHARE} ${dir} \
		${STAGEDIR}${PREFIX}/share/themes/Numix \
		"! -name thumbnail.png ! -name all-assets* ! -path *scss*"
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/index.theme \
		${STAGEDIR}${PREFIX}/share/themes/Numix

do-install-NOTIFYD-on:
	@cd ${WRKSRC}/src && \
		${COPYTREE_SHARE} xfce-notify-4.0 \
		${STAGEDIR}${PREFIX}/share/themes/Numix

.include <bsd.port.mk>
