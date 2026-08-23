PORTNAME=	devedeng
DISTVERSION=	4.22.0
CATEGORIES=	sysutils multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Gtk3 DVD disc authoring program
WWW=		https://rastersoft.com/programas/devede.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-gettext>0:devel/py-setuptools-gettext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libcanberra.so:audio/libcanberra
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycairo>0:graphics/py-pycairo@${PY_FLAVOR} \
		ffmpeg>1.2.6:multimedia/ffmpeg \
		dvdauthor:multimedia/dvdauthor \
		vcdimager:multimedia/vcdimager \
		mkisofs:sysutils/cdrtools

USES=		python gettext-tools gnome
USE_GITLAB=	yes
GL_ACCOUNT=	rastersoft
USE_GNOME=	gtk30 pygobject3:run
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFAULT=	BRASERO MPV
OPTIONS_MULTI=	PLAYER BURNER
OPTIONS_MULTI_BURNER=	BRASERO K3B XFBURN
OPTIONS_MULTI_PLAYER=	MPLAYER MPV VLC

BRASERO_DESC=	Burn discs with Brasero
BURNER_DESC=	CD/DVD Burning Program
K3B_DESC=	Burn discs with K3B
MPV_DESC=	MPV media player support
PLAYER_DESC=	Media Player
VLC_DESC=	VLC media player support
XFBURN_DESC=	Burn discs with xfburn

BRASERO_RUN_DEPENDS=	brasero:sysutils/brasero
K3B_RUN_DEPENDS=	k3b:sysutils/k3b
MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=	mpv:multimedia/mpv
VLC_RUN_DEPENDS=	vlc:multimedia/vlc
XFBURN_RUN_DEPENDS=	xfburn:sysutils/xfburn

pre-configure:
	${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/setup.py

.include <bsd.port.mk>
