PORTNAME=		jinja2-cli
PORTVERSION=		0.8.2
PORTREVISION=	1
CATEGORIES=		textproc python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		otis@FreeBSD.org
COMMENT=		Jinja2 CLI tool
WWW=		https://github.com/mattrobenolt/jinja2-cli

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}markupsafe>0:textproc/py-markupsafe@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}
TEST_DEPENDS=		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=			python

OPTIONS_DEFINE=		TEST TOML XML YAML
OPTIONS_DEFAULT=	TEST TOML XML YAML

TOML_DESC=		TOML format or parser support
TOML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR}

XML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xmltodict>0:devel/py-xmltodict@${PY_FLAVOR}

YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

.include <bsd.port.options.mk>

USE_PYTHON=		autoplist concurrent distutils
USE_GITHUB=		yes
GH_ACCOUNT=		mattrobenolt
.if ${PORT_OPTIONS:MTEST}
TEST_TARGET=		test
.endif

NO_ARCH=		yes

TEST_ENV=	       TMPDIR=${WRKDIR}

do-test:
	@cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} ${LOCALBASE}/bin/tox-${PYTHON_VER} -v

.include <bsd.port.mk>
