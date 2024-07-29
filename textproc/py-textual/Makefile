PORTNAME=	textual
PORTVERSION=	0.74.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern Text User Interface framework
WWW=		https://github.com/Textualize/textual

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.2.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown-it-py>=2.1.0:textproc/py-markdown-it-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.3.3:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.4.0<5:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	SYNTAX
SYNTAX_DESC=	Syntax support

SYNTAX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tree-sitter>=0.20.1<0.21:devel/py-tree-sitter@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tree-sitter-languages>=1.10.2<1.10.2_99:devel/py-tree-sitter-languages@${PY_FLAVOR}

.include <bsd.port.mk>
