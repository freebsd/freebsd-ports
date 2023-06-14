PORTNAME=	django-pyscss
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Makes it easier to use PySCSS in Django
WWW=		https://github.com/fusionbox/django-pyscss

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=1.4:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscss>=1.3.4:textproc/py-pyscss@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
