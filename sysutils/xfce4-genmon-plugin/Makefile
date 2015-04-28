# Created by: Matt Lancereau <ports@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-genmon-plugin
PORTVERSION=	3.4.0
PORTREVISION=	4
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Generic Monitor Xfce4 panel plugin

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gettext gmake libtool pkgconfig xfce tar:bzip2
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	panel

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

.include <bsd.port.mk>
