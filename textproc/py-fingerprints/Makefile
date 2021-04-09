PORTNAME=	fingerprints
DISTVERSION=	1.0.1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Easy comparing and cross-referencing of companies and people

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}normality>=2.0.0:textproc/py-normality@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	yes
GH_ACCOUNT=	alephdata
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.pre.mk>
# Set a locale to avoid build/configure errors.  The UTF-8 mode is enabled by
# default when the locale is C since Python 3.7.
.if ${PYTHON_REL} < 30700
USE_LOCALE=	en_US.UTF-8
.endif

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.post.mk>
