PORTNAME=	mailman
PORTVERSION=	3.3.1
CATEGORIES=	mail
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	GNU Mailing List Management System, Core

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosmtpd>=1.1:mail/py-aiosmtpd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}alembic>0:databases/py-alembic@${PY_FLAVOR} \
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

USES=		python:3.5+
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	mailman

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USERS=		mailman
GROUPS=		mailman

NO_ARCH=	yes

.include <bsd.port.mk>
