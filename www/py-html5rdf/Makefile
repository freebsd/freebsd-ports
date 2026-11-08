PORTNAME=	html5rdf
PORTVERSION=	1.2.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML parser based on the WHATWG HTML specification
WWW=		https://github.com/RDFLib/html5rdf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL CHARDET GENSHI LXML
ALL_DESC=	All optional dependencies
ALL_IMPLIES=	CHARDET GENSHI LXML
CHARDET_DESC=	Character encoding fallback
GENSHI_DESC=	Tree walker via genshi
LXML_DESC=	Tree builder/walker via lxml

CHARDET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=2.2.1,1:textproc/py-chardet@${PY_FLAVOR}
GENSHI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}genshi>=0.7.1:textproc/py-genshi@${PY_FLAVOR}
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.4.0:devel/py-lxml@${PY_FLAVOR}

.include <bsd.port.mk>
