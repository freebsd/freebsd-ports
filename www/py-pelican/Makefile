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

RUN_DEPENDS=	rst2html:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}feedgenerator>=1.6:${PORTSDIR}/www/py-feedgenerator \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}blinker>0:${PORTSDIR}/devel/py-blinker \
		${PYTHON_PKGNAMEPREFIX}unidecode>0:${PORTSDIR}/converters/py-unidecode \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	getpelican

OPTIONS_DEFINE=		MARKDOWN SYNTAX
OPTIONS_DEFAULT=	MARKDOWN SYNTAX

MARKDOWN_DESC=		Markdown markup language format support
MARKDOWN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:${PORTSDIR}/textproc/py-markdown

SYNTAX_DESC=		Syntax Highlighting (via pygments)
SYNTAX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.4:${PORTSDIR}/textproc/py-pygments

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
