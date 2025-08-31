PORTNAME=	tartube
DISTVERSION=	2.5.164
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	GUI front-end for youtube-dl/yt-dlp, written in Python
WWW=		https://github.com/axcore/tartube

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.8:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.7.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}moviepy>=1.0.3:multimedia/py-moviepy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}playsound>=1.3.0:audio/py-playsound@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}streamlink>=5.5.1:multimedia/streamlink@${PY_FLAVOR} \
		aria2c:www/aria2 \
		AtomicParsley:multimedia/atomicparsley \
		ffmpeg:multimedia/ffmpeg \
		yt-dlp:www/yt-dlp

USES=		gnome python
USE_GNOME=	pygobject3:run
USE_PYTHON=	autoplist distutils

MAKE_ENV=	TARTUBE_PKG_STRICT=1

NO_ARCH=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_MAKE_ENV=	WITH_LOCALE=yes

post-patch:
	${SED} -i.bak -e "s|\( = '\)/usr/share/tartube|\1${DATADIR}|1" \
		-e "s|\(version = \).*|\1'${PORTVERSION}',|1" \
		-e "s|\(sound_path\) + '/'|\1|1" \
		-e "s|/usr\(/share/locale\)|${PREFIX}\1|g" \
		${WRKSRC}/setup.py
	${SED} -i.bak -e "s|'/', 'usr', 'share', __main__.__packagename__|'${DATADIR}'|g" \
		-e "s|\(self.ytdl_path =\) None|\1 '${LOCALBASE}/bin/yt-dlp'|1" \
		${WRKSRC}/tartube/mainapp.py \
		${WRKSRC}/tartube/mainwin.py

.include <bsd.port.mk>
