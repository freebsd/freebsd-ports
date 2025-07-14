PORTNAME=	searxng
DISTVERSION=	20250711
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Free internet metasearch engine
WWW=		https://docs.searxng.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=0:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasttext-predict>=0:textproc/py-fasttext-predict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-babel>=0:devel/py-flask-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx-socks>=0:www/py-httpx-socks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langdetect>=0:textproc/py-langdetect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown-it-py>=0:textproc/py-markdown-it-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgspec>=0:devel/py-msgspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytomlpp>=0:textproc/py-pytomlpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=0:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=0:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvloop>=0:devel/py-uvloop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}valkey>=0:databases/py-valkey@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_TAGNAME=	d5743398539263f2c0cac676e073a08cb3eb6eb8
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	searxng

CONFLICTS=	searx

NO_ARCH=	yes

SUB_FILES=	searxng
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

post-patch: # expect dependencies to be backwards-compatible, otherwise it is difficult to have a port
	@${REINPLACE_CMD} -e 's|==|>=|' ${WRKSRC}/requirements.txt

post-install:
# move settings to etc/ /usr/local/lib/python3.x/site-packages/searx/settings.yml
	@${MV} ${STAGEDIR}${PYTHON_SITELIBDIR}/searx/settings.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yml.sample
	@${LN} -s ${PREFIX}/etc/${PORTNAME}.yml ${STAGEDIR}${PYTHON_SITELIBDIR}/searx/settings.yml

.include <bsd.port.mk>
