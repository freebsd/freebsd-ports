PORTNAME=	quodlibet
DISTVERSION=	4.7.1
CATEGORIES=	multimedia audio python
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/release-${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	aly@aaronly.me
COMMENT=	Music library/editor/player written in Python
WWW=		https://quodlibet.readthedocs.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycairo>=1.19:graphics/py-pycairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.11:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.45:audio/py-mutagen@${PY_FLAVOR}
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

USES=		desktop-file-utils gettext gnome gstreamer python shebangfix
SHEBANG_FILES=	exfalso.py operon.py quodlibet.py quodlibet/packages/update.sh
SUB_FILES=	pkg-message
USE_PYTHON=	autoplist pep517
USE_GNOME=	gtk30 pygobject3
USE_GSTREAMER=	good

NO_ARCH=	yes

OPTIONS_DEFINE=		PULSEAUDIO

PULSEAUDIO_DESC=	Support PulseAudio
PULSEAUDIO_USE=		GSTREAMER=pulse

.include <bsd.port.mk>
