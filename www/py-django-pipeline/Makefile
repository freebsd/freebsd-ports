# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-pipeline
PORTVERSION=	1.6.10
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Asset (css/js) packaging library for Django

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
USES=		python:2.7+
USE_PYTHON=	autoplist distutils

CONFLICTS=	py[23][0-9]-django-pipeline13-[0-9]*

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>0:devel/py-futures
.endif

.include <bsd.port.post.mk>
