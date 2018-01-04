# $FreeBSD$

PORTNAME=	asciinema
PORTVERSION=	1.4.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for recording and sharing terminal sessions

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:www/py-requests@${FLAVOR} \
		ca_root_nss>=0:security/ca_root_nss

USES=		python:3.3+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
