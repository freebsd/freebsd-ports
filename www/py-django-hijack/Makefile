PORTNAME=	django-hijack
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		https://ports.caomhin.org/:npmcache
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache

MAINTAINER=	ports@caomhin.org
COMMENT=	Allows Django superusers to login as other users

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR} \
		npm:www/npm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=2.2:www/py-django32@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-django>0:devel/py-pytest-django@${PY_FLAVOR}

USES=		gettext-tools:build python:3.6+
USE_PYTHON=	distutils autoplist

MAKE_ENV=	npm_config_offline=true
TEST_ENV=	DJANGO_SETTINGS_MODULES=hijack.tests.test_app.settings PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

_MY_NPMCACHE=	${WRKDIR}/.npm

# Add remaining files (e.g. *.po) that aren't recorded by setuptools
# during install.
post-install:
	@${FIND} ${STAGEDIR} -type f -o -type l | \
		${SORT} | ${SED} -e 's|${STAGEDIR}||' \
		> ${WRKDIR}/.PLIST.pymodtmp

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts=

# Helper target to make the generation of the npm cache easier
make-npm-cache: extract
	@${RM} -r ${_MY_NPMCACHE}
	@cd ${WRKSRC}/ \
		&& ${SETENV} HOME=${WRKDIR} ${LOCALBASE}/bin/npm ci
	@cd ${_MY_NPMCACHE} \
		&& ${RM} _locks anonymous-cli-metrics.json
	@cd ${WRKDIR} \
		&& ${TAR} -czf ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} .npm \
		&& ${ECHO_CMD} "Please upload the file ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}"

.include <bsd.port.mk>
