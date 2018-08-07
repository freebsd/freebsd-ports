# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urlextract
PORTVERSION=	0.8.3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collects and extracts URLs from given text

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritools>=0:net/py-uritools@${PY_FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python:3.3+

.include <bsd.port.mk>
