# Created by: Loic Blot <loic.blot@unix-experience.fr>

PORTNAME=	searx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	www python

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Privacy-respecting, hackable metasearch engine

LICENSE=	AGPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-babel>0:devel/py-flask-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ndg-httpsclient>0:net/py-ndg-httpsclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>0:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvloop>0:devel/py-uvloop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langdetect>0:textproc/py-langdetect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx-socks>0:www/py-httpx-socks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}splinter>0:www/py-splinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${PY_FLAVOR}
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	asciimoo
USE_PYTHON=	distutils autoplist noflavors
USE_RC_SUBR=	searx

NO_ARCH=	yes

SUB_FILES=	searx pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

post-patch: # expect dependencies to be backwards-compatible, otherwise it is difficult to have a port
	@${REINPLACE_CMD} -e 's|==|>=|' ${WRKSRC}/requirements.txt

post-install:
	# move settings to etc/ /usr/local/lib/python3.x/site-packages/searx/settings.yml
	@${MV} ${STAGEDIR}${PYTHON_SITELIBDIR}/searx/settings.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}-settings.yml.sample
	@${LN} -s ${PREFIX}/etc/${PORTNAME}-settings.yml ${STAGEDIR}${PYTHON_SITELIBDIR}/searx/settings.yml

.include <bsd.port.mk>
