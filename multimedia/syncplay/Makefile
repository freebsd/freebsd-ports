# $FreeBSD$

PORTNAME=	syncplay
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	multimedia

MAINTAINER=	heckendorfc@gmail.com
COMMENT=	Synchronize video playback over networks

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR}

USES=		desktop-file-utils gmake python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	Syncplay

NO_ARCH=	yes

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
