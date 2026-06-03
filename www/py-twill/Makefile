PORTNAME=	twill
DISTVERSION=	3.3.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web browsing and testing language
WWW=		https://twill-tools.github.io/twill/ \
		https://github.com/twill-tool/twill

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=6:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.1:devel/py-pyparsing@${PY_FLAVOR}

NO_ARCH=	yes

CONFLICTS_INSTALL=	tex-web2c # both install

.include <bsd.port.mk>
