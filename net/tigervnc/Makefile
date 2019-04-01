# $FreeBSD$

PORTNAME=	tigervnc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	meta@FreeBSD.org
COMMENT=	High-performance, platform-neutral implementation of VNC (meta port)

USES=		metaport

OPTIONS_DEFINE=	SERVER VIEWER
OPTIONS_DEFAULT=	SERVER
SERVER_DESC=	Install TigerVNC server
VIEWER_DESC=	Install TigerVNC viewer
SERVER_RUN_DEPENDS=	vncserver:net/tigervnc-server
VIEWER_RUN_DEPENDS=	vncviewer:net/tigervnc-viewer

do-patch:	# noop
do-install:	# noop

.include <bsd.port.mk>
