# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsonfield
PORTVERSION=	2.1.1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}django-

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Reusable JSONField model for Django to store ad-hoc data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	This port will be deleted in the future, please switch to use www/py-jsonfield or\
		www/py-jsonfield2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=0:www/py-django111@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rpkilby
GH_PROJECT=	jsonfield

.include <bsd.port.mk>
