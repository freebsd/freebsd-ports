# Created by: Julien Laffaye <jlaffaye@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pelican
PORTVERSION=	3.6.3
PORTREVISION=	1
CATEGORIES=	www textproc python

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Static site generator written in Python

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rst2html:textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}feedgenerator>=1.6:www/py-feedgenerator \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}blinker>0:devel/py-blinker \
		${PYTHON_PKGNAMEPREFIX}unidecode>0:converters/py-unidecode \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	getpelican

OPTIONS_DEFINE=		MARKDOWN SYNTAX
OPTIONS_DEFAULT=	MARKDOWN SYNTAX

MARKDOWN_DESC=		Markdown markup language format support
MARKDOWN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown

SYNTAX_DESC=		Syntax Highlighting (via pygments)
SYNTAX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.4:textproc/py-pygments

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
