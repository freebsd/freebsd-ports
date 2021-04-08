PORTNAME=	caldav
PORTVERSION=	0.8.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	CalDAV (RFC4791) client library

LICENSE=	APACHE20 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.6.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.8.1:deskutils/py-vobject@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
