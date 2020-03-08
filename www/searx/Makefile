# Created by: Loic Blot <loic.blot@unix-experience.fr>
# $FreeBSD$

PORTNAME=	searx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	www python

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Privacy-respecting, hackable metasearch engine

LICENSE=	AGPLv3

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Babel>0:devel/py-flask-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>0:net/py-ndg_httpsclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}splinter>0:www/py-splinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${PY_FLAVOR}

USES=		python:2.7
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
	# workaround for https://github.com/asciimoo/searx/issues/1208
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/tests
	@${REINPLACE_CMD} -e 's|.*/tests/.*||' ${_PYTHONPKGLIST}
	# move settings to etc/ /usr/local/lib/python2.7/site-packages/searx/settings.yml
	@${MV} ${STAGEDIR}${PYTHON_SITELIBDIR}/searx/settings.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}-settings.yml.sample
	@${LN} -s ${PREFIX}/etc/${PORTNAME}-settings.yml ${STAGEDIR}${PYTHON_SITELIBDIR}/searx/settings.yml

.include <bsd.port.mk>
