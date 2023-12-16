PORTNAME=	grip
PORTVERSION=	4.6.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Preview GitHub Markdown files locally before committing
WWW=		https://github.com/joeyespo/grip

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>=0.4.0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.5.1:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0.10.1:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}path-and-address>=2.0.1:www/py-path-and-address@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0.7:www/py-werkzeug@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	grip
NO_ARCH=	yes

.include <bsd.port.mk>
