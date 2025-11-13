PORTNAME=	mkdocstrings-crystal
DISTVERSION=	0.3.8
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocstrings_crystal-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Crystal language doc generator for mkdocstrings
WWW=		https://github.com/mkdocstrings/crystal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown-callouts>=0.1.0:textproc/py-markdown-callouts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-autorefs>=0.3.1:textproc/py-mkdocs-autorefs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=1.1.1:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.2:devel/py-Jinja2@${PY_FLAVOR}
# textproc/py-mkdocstrings belongs to RUN_DEPENDS as well but would cause
# a circular dependency (via py-mkdocstrings' CRYSTAL option)

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
