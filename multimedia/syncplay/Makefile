# $FreeBSD$

PORTNAME=	syncplay
PORTVERSION=	1.3.4
CATEGORIES=	multimedia

MAINTAINER=	heckendorfc@gmail.com
COMMENT=	Synchronize video playback over networks

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	Syncplay

USES=		desktop-file-utils gmake python:2 twisted
USE_TWISTED=	run

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	GUI VLC
OPTIONS_DEFAULT=	GUI VLC CLIENT SERVER
OPTIONS_SUB=	yes
OPTIONS_MULTI=	MODES
OPTIONS_MULTI_MODES=	CLIENT SERVER

VLC_DESC=	Support for VLC media player

MAKEFILE=	GNUmakefile

GUI_RUN_DEPENDS=	pyside-py2?>=1.1.2:devel/pyside

VLC_MAKE_ARGS=	VLC_SUPPORT=true
VLC_MAKE_ARGS_OFF=	VLC_SUPPORT=false
CLIENT_INSTALL_TARGET=	install-client
SERVER_INSTALL_TARGET=	install-server

.include <bsd.port.mk>
