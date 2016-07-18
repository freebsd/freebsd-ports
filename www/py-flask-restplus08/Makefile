# $FreeBSD$

PORTNAME=	flask-restplus
PORTVERSION=	0.8.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	08

MAINTAINER=	andrej@ebert.su
COMMENT=	Extension for Flask that adds support for quickly building REST APIs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask-RESTful>=0.3.2:www/py-flask-restful \
		${PYTHON_PKGNAMEPREFIX}six>=1.3.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}aniso8601>=0.82:devel/py-aniso8601

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}rednose>0:devel/py-rednose \
		${PYTHON_PKGNAMEPREFIX}blinker>0:devel/py-blinker \
		${PYTHON_PKGNAMEPREFIX}tzlocal>0:devel/py-tzlocal

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}flask-restplus
PORTSCOUT=	limit:^0\.8

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
