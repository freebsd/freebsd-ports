# Created by: ijliao
# $FreeBSD$

PORTNAME=	mechanize
PORTVERSION=	0.4.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Stateful programmatic web browsing in Python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>=0.9:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5-parser>0:www/py-html5-parser@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
