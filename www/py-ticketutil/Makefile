PORTNAME=	ticketutil
PORTVERSION=	1.8.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python ticketing utility supporting JIRA, RT, Redmine, Bugzilla, and ServiceNow
WWW=		https://github.com/dmranck/ticketutil

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gssapi>=1.2.0:security/py-gssapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.6.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-kerberos>=0.8.0:security/py-requests-kerberos@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
