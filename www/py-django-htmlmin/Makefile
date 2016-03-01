# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	django-htmlmin
PORTVERSION=	0.9.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	HTML minifier for Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bs4/element.py:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_SITELIBDIR}/html5lib/html5parser.py:${PORTSDIR}/www/py-html5lib

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
