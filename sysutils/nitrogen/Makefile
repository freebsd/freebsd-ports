# Created by: Jonathan Liu <Net147@hotmail.com>
# $FreeBSD$

PORTNAME=	nitrogen
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.l3ib.org/nitrogen/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Background browser and setter for X windows

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

LICENSE=	GPLv2

USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-inotify
CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

OPTIONS_DEFINE=	XINERAMA
OPTIONS_DEFAULT=	XINERAMA

MAN1=		nitrogen.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXINERAMA}
CONFIGURE_ARGS+=--enable-xinerama
USE_XORG+=	xinerama
.else
CONFIGURE_ARGS+=--disable-xinerama
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,#!/bin/bash,#!${LOCALBASE}/bin/bash,' \
		${WRKSRC}/data/icon-theme-installer

.include <bsd.port.mk>
