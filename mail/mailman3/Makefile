PORTNAME=	mailman
DISTVERSION=	3.3.10
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	GNU Mailing List Management System, Core
WWW=		https://www.list.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosmtpd>=1.4.3:mail/py-aiosmtpd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}alembic>0:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}atpublic>0:devel/py-atpublic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}authheaders>=0.16:mail/py-authheaders@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}authres>=1.0.1:mail/py-authres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.14.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}falcon>=3.1.3:www/py-falcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flufl.bounce>=4.0:mail/py-flufl.bounce@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flufl.i18n>=3.2:devel/py-flufl.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flufl.lock>=5.1:devel/py-flufl.lock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazr.config>0:devel/py-lazr.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>0:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>0:devel/py-zope.configuration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.event>0:devel/py-zope.event@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=5.0:devel/py-zope.interface@${PY_FLAVOR}

USES=		cpe python

CPE_VENDOR=	gnu
USE_PYTHON=	autoplist concurrent pep517
USE_RC_SUBR=	mailman
NO_ARCH=	yes
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
USERS=		mailman
GROUPS=		mailman

.include <bsd.port.mk>
