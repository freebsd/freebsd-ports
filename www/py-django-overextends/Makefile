# Created by: René Ladan <rene@freebsd.org>
# $FreeBSD$

PORTNAME=	django-overextends
PORTVERSION=	0.4.3
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django reusable app enabling circular template inheritance

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.11:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-me>=0.1.2:textproc/py-sphinx-me@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
