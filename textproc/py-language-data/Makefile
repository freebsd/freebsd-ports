PORTNAME=	language-data
PORTVERSION=	1.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	language_data-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Supplementary data about languages used by the langcodes module
WWW=		https://github.com/rspeer/language_data

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marisa-trie>=0.7.7:devel/py-marisa-trie@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
