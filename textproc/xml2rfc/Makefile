PORTNAME=	xml2rfc
PORTVERSION=	3.30.1
CATEGORIES=	textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Tool to create RFCs and related documents from XML
WWW=		https://xml2rfc.tools.ietf.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.44.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=5.3.0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.5.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}country>=22.3.5:devel/py-country@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=3.1.0:devel/py-intervaltree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-i18n-address>=3.0.0:devel/py-google-i18n-address@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configargparse>=1.2.3:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.2.5:devel/py-wcwidth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=3.6.0:devel/py-platformdirs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent optsuffix

NO_ARCH=	yes

.include <bsd.port.mk>
