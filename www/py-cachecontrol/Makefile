PORTNAME=	cachecontrol
DISTVERSION=	0.14.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

# patch build tool from uv-build (since 0.14.4) to flit-core for FreeBSD compatability
# https://github.com/psf/cachecontrol/pull/415
PATCH_SITES=	https://github.com/psf/cachecontrol/commit/
PATCHFILES=	\
	a286f6b184227e62447410a8c0d9c084c1bbb4c0.patch:-p1 \
	5c8a4e0ebf18e68f34b7641b54922c90d9ae9db6.patch:-p1 \
	e0540b3a33921204f7fdd77c32d93ed267b8bad8.patch:-p1 \


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
USE_PYTHON=	pep517 autoplist concurrent pytest # 24 tests fail, see https://github.com/psf/cachecontrol/issues/331
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

.include <bsd.port.mk>
