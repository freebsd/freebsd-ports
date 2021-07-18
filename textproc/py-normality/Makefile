PORTNAME=	normality
DISTVERSION=	2.1.1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Micro-library to normalize text strings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}banal>=1.0.1:devel/py-banal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text-unidecode>=0:converters/py-text-unidecode@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	yes
GH_ACCOUNT=	pudo
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=		ICU
OPTIONS_DEFAULT=	ICU

ICU_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyicu>=1.9.3:devel/py-pyicu@${PY_FLAVOR}

.include <bsd.port.pre.mk>
# Set a locale to avoid build/configure errors.  The UTF-8 mode is enabled by
# default when the locale is C since Python 3.7.
.if ${PYTHON_REL} < 30700
USE_LOCALE=	en_US.UTF-8
.endif

do-test:
	@cd ${WRKSRC} && ${SET_ENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.post.mk>
