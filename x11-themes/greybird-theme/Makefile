# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	greybird
PORTVERSION=	3.22.9
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-themes xfce
PKGNAMESUFFIX=	-theme

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk and xfwm4 themes for the Xfce Desktop

LICENSE=	GPLv2 CC-BY-SA-3.0
LICENSE_COMB=	dual

RUN_DEPENDS=	gtk-murrine-engine>=0.98.1:x11-themes/gtk-murrine-engine

PORTSCOUT=	limit:^3\.22\.

GH_ACCOUNT=	shimmerproject
GH_PROJECT=	Greybird

USE_GITHUB=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	NOTIFYD
OPTIONS_DEFAULT=	NOTIFYD
NOTIFYD_DESC=	Install xfce4-notifyd theme

.include <bsd.port.options.mk>

post-patch:
# Remove .orig file
	@${RM} ${WRKSRC}/gtk-?.0/*.orig

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Greybird
.for dir in gtk-2.0 gtk-3.0 plank xfwm4
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/share/themes/Greybird
.endfor

.if ${PORT_OPTIONS:MNOTIFYD}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} xfce-notify-4.0/ \
		${STAGEDIR}${PREFIX}/share/themes/Greybird
PLIST_SUB+=	NOTIFYD=""
.else
PLIST_SUB+=	NOTIFYD="@comment "
.endif

.include <bsd.port.mk>
