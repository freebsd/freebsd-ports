# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	graphite-api
PORTVERSION=	1.1.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Graphite-web, without the interface - just the rendering HTTP API

LICENSE=	APACHE20

RUN_DEPENDS=	\
			${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
			${PYTHON_PKGNAMEPREFIX}Flask>=0.10.1:www/py-flask \
			${PYTHON_PKGNAMEPREFIX}Flask-Cache>=0.13.1:www/py-flask-cache \
			${PYTHON_PKGNAMEPREFIX}tzlocal>=1.1.1:devel/py-tzlocal \
			${PYTHON_PKGNAMEPREFIX}structlog>=16.0.0:devel/py-structlog \
			${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.0:devel/py-pyparsing \
			${PYTHON_PKGNAMEPREFIX}yaml>3.1:devel/py-yaml \
			${PYTHON_PKGNAMEPREFIX}cairocffi>=0.7.2:graphics/py-cairocffi \
			${PYTHON_PKGNAMEPREFIX}gunicorn>=19.4.1:www/py-gunicorn \
			xorg-fonts-truetype>=0:x11-fonts/xorg-fonts-truetype

USES=		python
USE_PYTHON=	autoplist distutils
.include <bsd.port.mk>
