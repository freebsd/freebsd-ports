# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-modelcluster
PORTVERSION=	4.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django extension for working with clusters of models as a single unit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use www/py-django-modelcluster instead
EXPIRATION_DATE=2020-01-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=2015.2:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.

.include <bsd.port.mk>
