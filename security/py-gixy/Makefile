PORTNAME=	gixy
PORTVERSION=	0.1.21
CATEGORIES=	security www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Tool to analyze Nginx configuration for security misconfiguration
WWW=		https://github.com/yandex/gixy

LICENSE=	APACHE20

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}argparse>=1.4.0:devel/py-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cached-property>=1.2.0:devel/py-cached-property@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configargparse>=0.11.0:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.8:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=1.5.5:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.1.0:devel/py-six@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
