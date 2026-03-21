PORTNAME=	html5lib
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/html5lib/html5lib-python/commit/
PATCHFILES=	b90dafff1bf342d34d539098013d0b9f318c7641.patch:-p1 \
		2ba10ae9c0852318aee4dfece8cd8b49bfe48682.patch:-p1

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python based HTML parser based on the HTML5 spec
WWW=		https://github.com/html5lib/html5lib-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webencodings>0:converters/py-webencodings@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cpe python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
