# $FreeBSD$

PORTNAME=	fteproxy
DISTVERSION=	0.2.19
CATEGORIES=	security net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Programmable proxy for censorship circumvention

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=17.9.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libfte>=0.1.0:net/py-libfte@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}obfsproxy-tor>=0.2.13:security/py-obfsproxy-tor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyptlib>=0.0.6:security/py-pyptlib@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_BUILD=	yes

.include <bsd.port.mk>
