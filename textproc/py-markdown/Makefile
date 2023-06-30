PORTNAME=	markdown
PORTVERSION=	3.3.7
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Markdown-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python implementation of Markdown
WWW=		https://github.com/Python-Markdown/markdown

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=36.6:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.4:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
