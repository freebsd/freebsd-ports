PORTNAME=	pyramid-mako
PORTVERSION=	1.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyramid_mako-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mako template bindings for the Pyramid web framework
WWW=		https://github.com/Pylons/pyramid_mako

LICENSE=	REPOZE
LICENSE_NAME=	Repoze Public License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mako>=1.1.0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyramid>=0:www/py-pyramid@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webtest>=1.3.1:www/py-WebTest@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v

.include <bsd.port.mk>
