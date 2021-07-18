PORTNAME=	grip
PORTVERSION=	4.5.2
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Preview GitHub Markdown files locally before committing

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>=0.4.0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.5.1:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.10.1:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}path-and-address>=2.0.1:www/py-path-and-address@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.1:www/py-requests@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	grip
NO_ARCH=	yes

.include <bsd.port.mk>
