PORTNAME=	hotdoc
PORTVERSION=	0.17.4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Documentation tool micro-framework
WWW=		https://hotdoc.github.io/ \
		https://github.com/hotdoc/hotdoc

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}backports.entry-points-selectable>=0:devel/py-backports.entry-points-selectable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus-deviation>=0.4.0:devel/py-dbus-deviation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}schema>=0:devel/py-schema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toposort>=1.4:devel/py-toposort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheezy.template>=0:textproc/py-wheezy.template@${PY_FLAVOR}

USES=		cmake:indirect gnome pkgconfig python
USE_GNOME=	glib20 libxml2
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	HOTDOC_BUILD_C_EXTENSION=enabled

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
