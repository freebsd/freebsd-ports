PORTNAME=	cachecontrol
DISTVERSION=	0.15.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Caching algorithms in httplib2 for use with requests session object
WWW=		https://github.com/psf/cachecontrol

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.11<5:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.5.2<2.0.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.16.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cherrypy>0:www/py-cherrypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest
NO_ARCH=	yes

# fix "ZIP does not support timestamps before 1980"
# https://github.com/pypa/flit/issues/446
MAKE_ENV=	SOURCE_DATE_EPOCH=347151600

CONFLICTS_INSTALL=	py*-cachecontrol # bin/doesitcache

OPTIONS_DEFINE=		FILECACHE REDIS
OPTIONS_DEFAULT=	FILECACHE
FILECACHE_DESC=		FileCache support
REDIS_DESC=		Redis support

FILECACHE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>=3.7.1:sysutils/py-filelock@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=2.10.5:databases/py-redis@${PY_FLAVOR}

# tests as of 0.15.0: 122 passed in 15.93s

.include <bsd.port.mk>
