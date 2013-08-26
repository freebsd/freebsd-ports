# Created by: Olivier Duchateau
# $FreeBSD$
#

PORTNAME=	greybird
PORTVERSION=	1.2
CATEGORIES=	x11-themes xfce
MASTER_SITES=	GH GHC \
	LOCAL/olivierd
PKGNAMESUFFIX=	-theme

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Gtk and xfwm4 themes for the Xfce Desktop

RUN_DEPENDS=	gtk-murrine-engine>=0.98.1:${PORTSDIR}/x11-themes/gtk-murrine-engine \
	gtk3-unico-engine>=1.0.2:${PORTSDIR}/x11-themes/gtk3-unico-engine

GH_ACCOUNT=	shimmerproject
GH_PROJECT=	Greybird
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	6424d8a

USE_GITHUB=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	NOTIFYD
OPTIONS_DEFAULT=	NOTIFYD
NOTIFYD_DESC=	Install xfce4-notifyd theme

.include <bsd.port.options.mk>

post-extract:
# Remove Unity and Lightdm themes
.for file in lightdm-*-greeter.css unity.css
	@${RM} ${WRKSRC}/gtk-3.0/apps/${file}
.endfor

post-patch:
# Remove .orig file
	@${RM} ${WRKSRC}/gtk-3.0/*.orig

do-install:
	@${MKDIR} ${PREFIX}/share/themes/Greybird
.for dir in gtk-2.0 gtk-3.0 xfwm4
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${dir} ${PREFIX}/share/themes/Greybird
.endfor

.if ${PORT_OPTIONS:MNOTIFYD}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} xfce-notify-4.0/ \
		${PREFIX}/share/themes/Greybird
PLIST_SUB+=	NOTIFYD=""
.else
PLIST_SUB+=	NOTIFYD="@comment "
.endif

.include <bsd.port.mk>
