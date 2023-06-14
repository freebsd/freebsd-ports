PORTNAME=	mailman
DISTVERSION=	3.3.8
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	GNU Mailing List Management System, Core
WWW=		https://www.list.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosmtpd>=1.1:mail/py-aiosmtpd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}alembic14>0:databases/py-alembic14@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}atpublic>0:devel/py-atpublic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.14.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}falcon>=1.0.0.rc1:www/py-falcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flufl.bounce>0:mail/py-flufl.bounce@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flufl.i18n>=2.0:devel/py-flufl.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flufl.lock>=3.1:devel/py-flufl.lock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazr.config>0:devel/py-lazr.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>1.2.3:databases/py-sqlalchemy12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>0:devel/py-zope.configuration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.event>0:devel/py-zope.event@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	gnu
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	mailman
NO_ARCH=	yes
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
USERS=		mailman
GROUPS=		mailman

.include <bsd.port.mk>
