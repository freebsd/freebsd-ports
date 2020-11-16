# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pylsqpack
PORTVERSION=	0.3.11
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for the ls-qpack QPACK library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang python:3.5+
USE_PYTHON=	autoplist concurrent distutils

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py test

.include <bsd.port.mk>
