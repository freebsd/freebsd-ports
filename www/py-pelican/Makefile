# Created by: Julien Laffaye <jlaffaye@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pelican
PORTVERSION=	3.6.3
PORTREVISION=	3
CATEGORIES=	www textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Static site generator written in Python

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedgenerator>=1.6:www/py-feedgenerator@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>0:devel/py-blinker@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>0:converters/py-unidecode@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR}

NO_ARCH=	yes
USES=		python shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	pelican/tools/templates/publishconf.py.in \
		pelican/tools/*.py

GH_ACCOUNT=	getpelican

OPTIONS_DEFINE=		MARKDOWN SYNTAX
OPTIONS_DEFAULT=	MARKDOWN SYNTAX

MARKDOWN_DESC=		Markdown markup language format support
MARKDOWN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${FLAVOR}

SYNTAX_DESC=		Syntax Highlighting (via pygments)
SYNTAX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.4:textproc/py-pygments@${FLAVOR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
