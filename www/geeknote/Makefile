# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geeknote
DISTVERSION=	0.2a
PORTREVISION=	2
CATEGORIES=	www python

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Command line client for Evernote

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}evernote>=1.17:www/py-evernote \
		${PYTHON_PKGNAMEPREFIX}html2text>0:textproc/py-html2text \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}markdown2>0:textproc/py-markdown2 \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}thrift>0:devel/py-thrift

USES=		python:-2.7
USE_GITHUB=	yes
USE_PYTHON=     autoplist distutils

GH_ACCOUNT=	VitaliyRodnenko
GH_TAGNAME=	7ea2255

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
