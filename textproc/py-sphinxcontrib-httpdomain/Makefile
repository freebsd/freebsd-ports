PORTNAME=	sphinxcontrib-httpdomain
DISTVERSION=	2.1.0
CATEGORIES=	textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sphinx domain for HTTP APIs
WWW=		https://github.com/sphinx-contrib/httpdomain

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.9.26:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=8.1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|0.12.22|0.12.19|g; s|, < 0.13.0||' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
