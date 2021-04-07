PORTNAME=	spdx-tools
DISTVERSION=	0.6.1
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Parses, validates and creates SPDX documents

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>=0:textproc/py-rdflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0:devel/py-xmltodict@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	py??-spdx-*
NO_ARCH=		yes
PORTEXAMPLES=		*

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${FIND} ${WRKSRC}/examples -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR} \;

do-test:
	@cd ${WRKSRC} && ${SETENV} LC_ALL=en_US.UTF-8 ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
