PORTNAME=	iris-vt-module
DISTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	IRIS Module enriching IOCs with VT insights
WWW=		https://github.com/dfir-iris/iris-vt-module

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyunpack>0:archivers/py-pyunpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virustotal-api>0:security/py-virustotal-api@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dfir-iris
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	5f2eb2a751ef3cce67f45ccd5753a2d32edc28df

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
