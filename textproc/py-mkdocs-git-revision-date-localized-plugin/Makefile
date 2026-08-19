PORTNAME=	mkdocs-git-revision-date-localized-plugin
PORTVERSION=	1.5.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocs_git_revision_date_localized_plugin-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enable displaying the localized date of the last git modification
WWW=		https://timvink.github.io/mkdocs-git-revision-date-localized-plugin/ \
		https://github.com/timvink/mkdocs-git-revision-date-localized-plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.7.0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1.44:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.0<2:textproc/py-mkdocs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
