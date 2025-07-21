PORTNAME=	bazarr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	net-p2p python
MASTER_SITES=	https://github.com/morpheus65535/bazarr/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	bazarr
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Automatic subtitle downloader for Radarr and Sonarr
WWW=		https://www.bazarr.media

LICENSE=	GPLv3

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=4.3.0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>1.12.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webrtcvad>=2.0.10:audio/py-webrtcvad@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		ffprobe:multimedia/ffmpeg \
		unrar:archivers/unrar

USES=		python zip

USE_RC_SUBR=	bazarr

NO_ARCH=	yes
SUB_FILES=	${PORTNAME} package_info
SUB_LIST=	MAINTAINER=${MAINTAINER} \
		PKGVERSION=${PKGVERSION} \
		PYTHON_CMD=${PYTHON_CMD} \
		USERS=${USERS}

NO_WRKSUBDIR=	yes

USERS=		bazarr
GROUPS=		bazarr

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}/bin/

post-install:
	${INSTALL_DATA} ${WRKDIR}/package_info ${STAGEDIR}/${DATADIR}/

.include <bsd.port.mk>
