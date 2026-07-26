PORTNAME=	django-markwhat
DISTVERSION=	2025.5.31
CATEGORIES=	www python textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Collection of template filters that implement common markup languages
WWW=		https://pypi.org/project/django-markwhat/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.3:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>0:www/py-django52@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		MARKDOWN
OPTIONS_DEFAULT=	MARKDOWN

MARKDOWN_DESC=		Support for Markdown

MARKDOWN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} '/license-files/d; s|^license = "BSD-3-Clause"|license = { text = "BSD-3-Clause" }|' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
