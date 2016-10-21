# $FreeBSD$

PORTNAME=	flask-restplus
PORTVERSION=	0.9.2
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	andrej@ebert.su
COMMENT=	Extension for Flask that adds support for quickly building REST APIs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.8:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}six>=1.3.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}aniso8601>=0.82:devel/py-aniso8601
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blinker>0:devel/py-blinker \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}flask-restplus08

USE_GITHUB=	yes
GH_ACCOUNT=	noirbizarre

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock
.endif

do-test:
	@${RM} -r ${TEST_WRKSRC}/build/lib/tests
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.post.mk>
