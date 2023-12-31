PORTNAME=	yt-dlp # www/py-yt-dlp is for extending yt-dlp, www/yt-dlp is an application for the end user
DISTVERSION=	2023.12.30
CATEGORIES=	www
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program for downloading videos from various platforms (devel files)
WWW=		https://github.com/yt-dlp/yt-dlp

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>0:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>0:security/py-pycryptodomex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.17:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>0:devel/py-websockets@${PY_FLAVOR}

USES=		gmake python shebangfix
USE_PYTHON=	concurrent flavors

SHEBANG_GLOB=	*.py

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=			FFMPEG RTMPDUMP SECRETSTORAGE
OPTIONS_DEFAULT=		FFMPEG RTMPDUMP
OPTIONS_SUB=			yes

FFMPEG_RUN_DEPENDS=		ffprobe:multimedia/ffmpeg

RTMPDUMP_DESC=			Use rtmpdump to download rtmp video streams
RTMPDUMP_RUN_DEPENDS=		rtmpdump:multimedia/rtmpdump

SECRETSTORAGE_DESC=		Build with ${PYTHON_PKGNAMEPREFIX}SecretStorage for secretstorage option
SECRETSTORAGE_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}SecretStorage>0:security/py-SecretStorage@${PY_FLAVOR}
SECRETSTORAGE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}SecretStorage>0:security/py-SecretStorage@${PY_FLAVOR}

do-install:
	# copy files
	cd ${WRKSRC} && \
		${GMAKE} PYTHON_SITELIBDIR=${STAGEDIR}${PYTHON_SITELIBDIR} freebsd-install-all-files
	# make the main file executable
	${CHMOD} +x ${STAGEDIR}${PYTHON_SITELIBDIR}/yt_dlp/__main__.py
	# create the symlink
	${RLN} ${STAGEDIR}${PYTHON_SITELIBDIR}/yt_dlp/__main__.py ${STAGEDIR}${PREFIX}/bin/yt-dlp-devel

.include <bsd.port.mk>
