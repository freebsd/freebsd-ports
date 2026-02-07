PORTNAME=	urlscan
DISTVERSION=	1.0.8
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Mutt and terminal url selector (similar to urlview)
WWW=		https://github.com/firecat53/urlscan

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.4.0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.25:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urwid>=1.2.1:devel/py-urwid@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} \
		-e '/^LICENSE =/d' ${WRKSRC}/pyproject.toml

post-patch-DOCS-off:
	${REINPLACE_CMD} \
		-e '/^"README.md" =/d' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
