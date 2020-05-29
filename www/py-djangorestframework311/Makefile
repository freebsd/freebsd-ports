# $FreeBSD$

PORTNAME=	djangorestframework
DISTVERSION=	3.11.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	311

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Django REST framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	Used as a transitional package for www/seahub, please use www/py-djangorestframework instead

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>0:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}djangorestframework \
			${PYTHON_PKGNAMEPREFIX}djangorestframework3* \
			${PYTHON_PKGNAMEPREFIX}dj22-djangorestframework
NO_ARCH=		yes

PORTSCOUT=	limit:^3\.11\.

.include <bsd.port.mk>
