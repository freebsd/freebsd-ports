PORTNAME=	sphinx-markdown-builder
# Before updating check XXX below
DISTVERSION=	0.6.11
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Sphinx extension to add markdown generation support
WWW=		https://github.com/liran-funaro/sphinx-markdown-builder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.48.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.21.2,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=9.0.4:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.10.0:devel/py-tabulate@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

# XXX: remove this target if the version of devel/py-setuptools is >= 77
post-patch:
	${REINPLACE_CMD} -E \
		-e '/^license-files/d' \
		-e 's/^(license = )("${LICENSE}")/\1{ text = \2 }/1' \
		-e 's/(setuptools>=)[.0-9]+/\163/1' \
			${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
