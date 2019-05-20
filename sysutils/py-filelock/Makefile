# $FreeBSD$

PORTNAME=	filelock
DISTVERSION=	3.0.11
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Platform independent file lock

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+ # fails on 27: https://github.com/benediktschmitt/py-filelock/issues/53
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
