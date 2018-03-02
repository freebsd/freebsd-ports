# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	obfsproxy
PORTVERSION=	0.2.13
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	security net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-tor

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Pluggable transport proxy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyptlib>=0.0.5:security/py-pyptlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.1:security/py-pycrypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist
SUB_FILES=	pkg-message
NO_ARCH=	yes

PYDISTUTILS_PKGNAME=	obfsproxy

.include <bsd.port.mk>
