PORTNAME=	bazarr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2-beta.11
CATEGORIES=	net-p2p python
MASTER_SITES=	https://github.com/morpheus65535/bazarr/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMESUFFIX=	-devel
DISTNAME=	bazarr
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}/${DISTVERSION}

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Automatic subtitle downloader for Radarr and Sonarr

LICENSE=	GPLv3

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.3.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webrtcvad>=2.0.10:audio/py-webrtcvad@${PY_FLAVOR} \
		ffprobe:multimedia/ffmpeg \
		unrar:archivers/unrar

USES=		python:3.7+ zip

USE_RC_SUBR=	bazarr

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		USERS=${USERS}

NO_WRKSUBDIR=	yes

USERS=		bazarr
GROUPS=		bazarr

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}

post-install:
	@${FIND} -s ${STAGEDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>
