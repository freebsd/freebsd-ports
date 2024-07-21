PORTNAME=	towncrier
PORTVERSION=	22.12.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Building newsfiles for your project
WWW=		https://github.com/twisted/towncrier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}incremental>=0:devel/py-incremental@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-default-group>=0:devel/py-click-default-group@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>=0:devel/py-incremental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
