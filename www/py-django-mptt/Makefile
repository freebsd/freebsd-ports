# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	django-mptt
PORTVERSION=	0.6.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Utilities for implementing a pre-order traversal tree in django

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.4.2:${PORTSDIR}/www/py-django
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes

USES=		gettext python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
