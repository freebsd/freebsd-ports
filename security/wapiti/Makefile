# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	wapiti
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Wapiti is a vulnerability scanner for web applications

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup32>=0:www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}requests>=1.2.3:www/py-requests

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
