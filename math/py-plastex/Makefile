PORTNAME=	plastex
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	plasTeX-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LaTeX Document Processing Framework
WWW=		https://github.com/plastex/plastex

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=7:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0.4.21:converters/py-unidecode@${PY_FLAVOR}

USES=		python tex
USE_PYTHON=	autoplist concurrent pep517
USE_TEX=	base:run

NO_ARCH=	yes

.include <bsd.port.mk>
