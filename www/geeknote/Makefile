# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geeknote
DISTVERSION=	0.2a
PORTREVISION=	3
CATEGORIES=	www python

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Command line client for Evernote

LICENSE=	GPLv2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}evernote>=1.17:www/py-evernote@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text2018>0:textproc/py-html2text2018@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown2>0:textproc/py-markdown2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thrift>0:devel/py-thrift@${PY_FLAVOR}

USES=		python:2.7
USE_GITHUB=	yes
USE_PYTHON=     autoplist distutils

GH_ACCOUNT=	VitaliyRodnenko
GH_TAGNAME=	7ea2255

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
