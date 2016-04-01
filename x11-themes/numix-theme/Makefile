# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	numix
PORTVERSION=	2.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-themes xfce
PKGNAMESUFFIX=	-theme

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Gtk and Xfwm4 flat themes for the Xfce Desktop

LICENSE=	GPLv3

RUN_DEPENDS=	gtk-murrine-engine>=0.98.1:x11-themes/gtk-murrine-engine

GH_ACCOUNT=	shimmerproject
GH_PROJECT=	Numix

USE_GITHUB=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	NOTIFYD
OPTIONS_DEFAULT=	NOTIFYD
NOTIFYD_DESC=	Install xfce4-notifyd theme

.include <bsd.port.options.mk>

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
