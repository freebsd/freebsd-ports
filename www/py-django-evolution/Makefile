# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-evolution
PORTVERSION=	0.6.9
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_evolution-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Database schema evolution tool for the Django web framework

DEPRECATED=	Django 1.4 extended support ended on 2015-10-01
EXPIRATION_DATE=	2015-12-09

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django14>=1.1.1:${PORTSDIR}/www/py-django14

USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
	${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
