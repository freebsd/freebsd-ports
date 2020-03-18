# Created by: jabley@automagic.org
# $FreeBSD$

PORTNAME=	xml2rfc
PORTVERSION=	2.40.1
CATEGORIES=	textproc
MASTER_SITES=	http://tools.ietf.org/tools/xml2rfc2/cli/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Tool to create RFCs and related documents from XML

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.2.8:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.5.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.1:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}country>=1.8:devel/py-country@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0.8.1:devel/py-pyflakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=3.0.1:devel/py-intervaltree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-i18n-address>=2.3.2:devel/py-google-i18n-address@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=1.0.1:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kitchen>=1.2.6:devel/py-kitchen@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent optsuffix

.include <bsd.port.mk>
