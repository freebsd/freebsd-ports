# $FreeBSD$

PORTNAME=	gfm
DISTVERSION=	0.1.3
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Github-flavored Markdown for the py-markdown module

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	Zopieux
GH_PROJECT=	py-${PORTNAME}
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+=build_sphinx

PORTDOCS=		*

post-install-DOCS-on:
	cd ${WRKSRC}/build/sphinx/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -path objects.inv"

.include <bsd.port.mk>
