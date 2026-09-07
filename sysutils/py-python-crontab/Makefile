PORTNAME=	python-crontab
PORTVERSION=	3.4.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Read and write crontab files using a direct API
WWW=		https://gitlab.com/doctormo/python-crontab

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}croniter>0:sysutils/py-croniter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cron-descriptor>0:sysutils/py-cron-descriptor@${PY_FLAVOR}

USES=		python shebangfix
SHEBANG_FILES=	${WRKSRC}/tests/data/crontest
USE_PYTHON=	autoplist distutils

USE_GITLAB=	yes
GL_ACCOUNT=	doctormo
GL_TAGNAME=	040c496686a6dd8739efee67024caf646e33623d

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
