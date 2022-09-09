PORTNAME=	caldav
PORTVERSION=	0.9.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	CalDAV (RFC4791) client library
WWW=		https://github.com/python-caldav/caldav

LICENSE=	APACHE20 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0:deskutils/py-vobject@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}icalendar>=0:devel/py-icalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}radicale>=0:www/radicale@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>0:devel/py-tzlocal@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

TEST_ENV=	TZ=UTC

NO_ARCH=	yes

do-test:
	cd ${WRKSRC}/.. && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
