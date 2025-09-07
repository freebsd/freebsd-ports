PORTNAME=	myst-parser
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	myst_parser-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extended commonmark compliant parser with bridges to docutils & sphinx
WWW=		https://myst-parser.readthedocs.io/en/latest/ \
		https://github.com/executablebooks/MyST-Parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.4<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.19,1<0.22,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown-it-py>=3.0<5:textproc/py-markdown-it-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mdit-py-plugins>=0.4.1<1:textproc/py-mdit-py-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=5,1<9,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	LINKIFY
LINKIFY_DESC=	Linkify extension

LINKIFY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}linkify-it-py>=2.0<3:textproc/py-linkify-it-py@${PY_FLAVOR}

.include <bsd.port.mk>
