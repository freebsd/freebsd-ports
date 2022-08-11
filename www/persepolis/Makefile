PORTNAME=	persepolis
PORTVERSION=	3.2.0
CATEGORIES=	www net ftp python

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical download manager (GUI for Aria2)

LICENSE=	GPLv3+

BUILD_DEPENDS=	aria2c:www/aria2 ffmpeg:multimedia/ffmpeg \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${LOCALBASE}/share/sounds/freedesktop/stereo/complete.oga:audio/freedesktop-sound-theme
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		xdg-mime:devel/xdg-utils yt-dlp:www/yt-dlp \
		${PYTHON_PKGNAMEPREFIX}PyOgg>0:audio/py-pyogg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		pyqt:5 python
USE_PYTHON=	autoplist distutils noflavors
USE_PYQT=	pyqt5
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}dm

# Preserve remote (as on server) modification time of downloaded files
post-patch:
	@${REINPLACE_CMD} -e "/aria2c/s/--no-conf/&', '-R/" \
		${WRKSRC}/persepolis/scripts/download.py

.include <bsd.port.mk>
