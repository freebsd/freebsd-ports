PORTNAME=	xml2rfc
PORTVERSION=	3.17.3
CATEGORIES=	textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Tool to create RFCs and related documents from XML
WWW=		https://xml2rfc.tools.ietf.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=4.9.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.5.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.1:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}country>=22.3.5:devel/py-country@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=3.0.1:devel/py-intervaltree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-i18n-address>=2.3.2:devel/py-google-i18n-address@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=1.0.1:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.4:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configargparse>=1.2.3:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=24.2.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=2.1.1:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.2.5:devel/py-wcwidth@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist concurrent optsuffix

.include <bsd.port.mk>
