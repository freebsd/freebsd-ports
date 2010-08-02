# Ports collection makefile for:	nitrogen
# Date created:				4 July 3007
# Whom:					Jonathan Liu <Net147@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	nitrogen
PORTVERSION=	1.5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.l3ib.org/nitrogen/files/

MAINTAINER=	Net147@hotmail.com
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

OPTIONS=	XINERAMA "Xinerama support" on

MAN1=		nitrogen.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_XINERAMA)
CONFIGURE_ARGS+=--disable-xinerama
.else
CONFIGURE_ARGS+=--enable-xinerama
USE_XORG+=	xinerama
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,#!/bin/bash,#!${LOCALBASE}/bin/bash,' \
		${WRKSRC}/data/icon-theme-installer

.include <bsd.port.post.mk>
