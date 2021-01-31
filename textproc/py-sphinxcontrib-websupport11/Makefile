# $FreeBSD$

PORTNAME=	sphinxcontrib-websupport
PORTVERSION=	1.1.2
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	11

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sphinx API for Web Apps

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use textproc/py-sphinxcontrib-websupport instead
EXPIRATION_DATE=2021-02-15

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# sphinxcontrib-websupport 1.2.0+ requires Python 3.5+
PORTSCOUT=	limit:^1\.1\.

.include <bsd.port.mk>
