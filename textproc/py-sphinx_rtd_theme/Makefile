PORTNAME=	sphinx_rtd_theme
PORTVERSION=	3.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Mobile-friendly py-sphinx theme
WWW=		https://github.com/readthedocs/sphinx_rtd_theme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils pytest

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=6,1<10,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.18,1<0.23,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-jquery>=4.0<5.0:textproc/py-sphinxcontrib-jquery@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
