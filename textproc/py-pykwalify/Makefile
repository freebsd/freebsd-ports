# $FreeBSD$

PORTNAME=	pykwalify
DISTVERSION=	1.7.0-15
DISTVERSIONSUFFIX=	-g02b7e21
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Python lib/cli for JSON/YAML schema validation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>=0.6.2:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.11.0:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.4.2:devel/py-dateutil@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.6.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testfixtures>=0:devel/py-testfixtures@${PY_FLAVOR}

USES=		python
# Switch to CHEESESHOP once version > 1.7.0 is released.
USE_GITHUB=	yes
GH_ACCOUNT=	Grokzen
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTEXAMPLES=	utf8-data.yml utf8-schema.yml

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
