# $FreeBSD$

PORTNAME=	syncplay
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
CATEGORIES=	multimedia

MAINTAINER=	heckendorfc@gmail.com
COMMENT=	Synchronize video playback over networks

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR}

USES=		desktop-file-utils gmake python:3.4+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Syncplay

SHEBANG_FILES=	syncplayClient.py \
		syncplayServer.py
MAKEFILE=	GNUmakefile
NO_ARCH=	yes

OPTIONS_DEFINE=	GUI VLC
OPTIONS_DEFAULT=	GUI VLC CLIENT SERVER
OPTIONS_SUB=	yes
OPTIONS_MULTI=	MODES
OPTIONS_MULTI_MODES=	CLIENT SERVER

CLIENT_DESC=	Client mode
SERVER_DESC=	Server mode
VLC_DESC=	Support for VLC media player

GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyside2>=0:devel/pyside2@${PY_FLAVOR}
VLC_MAKE_ARGS=		VLC_SUPPORT=true
VLC_MAKE_ARGS_OFF=	VLC_SUPPORT=false
CLIENT_INSTALL_TARGET=	install-client
SERVER_INSTALL_TARGET=	install-server

post-patch:
	@${REINPLACE_CMD} -e 's|path = os.path.dirname(os.path.dirname(__file__))|path = "'${DATADIR}'"|g' ${WRKSRC}/syncplay/utils.py

.include <bsd.port.mk>
