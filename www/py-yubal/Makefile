PORTNAME=	yubal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Self-hosted YouTube Music downloader

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${DISTVERSION}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mediafile>=0:devel/py-mediafile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathvalidate>=0:devel/py-pathvalidate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=0:devel/py-rapidfuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yt-dlp>=0:www/py-yt-dlp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ytmusicapi>=0:devel/py-ytmusicapi@${PY_FLAVOR} \
		rsgain:audio/rsgain

USES=		python
USE_PYTHON=	autoplist pep517
USE_GITHUB=	yes
GH_ACCOUNT=	guillevc

WRKSRC_SUBDIR=	packages/yubal

OPTIONS_DEFINE=		CLI
OPTIONS_DEFAULT=	CLI

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rich>=0:textproc/py-rich@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}typer>=0:devel/py-typer@${PY_FLAVOR}

.include <bsd.port.mk>
