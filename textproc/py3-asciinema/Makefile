# $FreeBSD$

PORTNAME=	asciinema
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for recording and sharing terminal sessions

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:www/py3-requests \
		ca_root_nss>=0:security/ca_root_nss

USES=		python:3.3+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
