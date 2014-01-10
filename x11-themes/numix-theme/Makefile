# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	numix
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	x11-themes xfce
MASTER_SITES=	GH GHC
PKGNAMESUFFIX=	-theme

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Gtk and Xfwm4 flat themes for the Xfce Desktop

LICENSE=	GPLv3

RUN_DEPENDS=	gtk-murrine-engine>=0.98.1:${PORTSDIR}/x11-themes/gtk-murrine-engine

GH_ACCOUNT=	shimmerproject
GH_PROJECT=	Numix
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	7b744e7

USE_GITHUB=	yes
NO_BUILD=	yes
USE_GNOME=	gtk30

OPTIONS_DEFINE=	NOTIFYD
OPTIONS_DEFAULT=	NOTIFYD
NOTIFYD_DESC=	Install xfce4-notifyd theme

.include <bsd.port.options.mk>

post-extract:
# Remove Unity theme
	@${RM} ${WRKSRC}/gtk-3.0/apps/unity.css

post-patch:
# Remove .orig files
	@${RM} ${WRKSRC}/gtk-?.0/*.orig

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Numix
.for dir in gtk-2.0 gtk-3.0 xfwm4
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/share/themes/Numix
.endfor

.if ${PORT_OPTIONS:MNOTIFYD}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} xfce-notify-4.0 \
		${STAGEDIR}${PREFIX}/share/themes/Numix
PLIST_SUB+=	NOTIFYD=""
.else
PLIST_SUB+=	NOTIFYD="@comment "
.endif

.include <bsd.port.mk>
