# Created by: Dan Langille
# $FreeBSD$

PORTNAME=	gixy
PORTVERSION=	0.1.3
CATEGORIES=	security www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Tool to analyze Nginx configuration for security misconfiguration

LICENSE=	APACHE20

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyparsing>=1.5.5:devel/py-pyparsing
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cached-property>=1.2.0:devel/py-cached-property
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.8:devel/py-Jinja2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}configargparse>=0.11.0:devel/py-configargparse

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
