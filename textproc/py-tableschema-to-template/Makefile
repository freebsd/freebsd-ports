PORTNAME=	tableschema-to-template
PORTVERSION=	0.0.13
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate an Excel template with input validation from Frictionless Table Schema
WWW=		https://github.com/hubmapconsortium/tableschema-to-template

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=1.0.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.13:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=1.2.8:textproc/py-xlsxwriter@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/VERSION

.include <bsd.port.mk>
