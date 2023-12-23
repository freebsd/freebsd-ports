PORTNAME=	devedeng
DISTVERSION=	4.17.0
PORTREVISION=	1
CATEGORIES=	sysutils multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fuz@fuz.su
COMMENT=	Gtk3 DVD disc authoring program
WWW=		https://rastersoft.com/programas/devede.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcanberra.so:audio/libcanberra
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		ffmpeg>1.2.6:multimedia/ffmpeg \
		dvdauthor:multimedia/dvdauthor \
		vcdimager:multimedia/vcdimager \
		mkisofs:sysutils/cdrtools

USES=		python gettext-tools gnome
USE_GITLAB=	yes
GL_ACCOUNT=	rastersoft
GL_TAGNAME=	b003c2bfe61a1001ea708501f8d36239782975ce
USE_GNOME=	gtk30
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes
PLIST_FILES=	bin/devede_ng

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

post-install:
	${LN} -s devede_ng.py ${STAGEDIR}${PREFIX}/bin/devede_ng

.include <bsd.port.mk>
