# $FreeBSD$

PORTNAME=	django-redis
PORTVERSION=	4.9.0
PORTREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Full featured Redis cache/session backend for Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.8:www/py-django@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=2.10.0:databases/py-redis@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fakeredis>=0:databases/py-fakeredis@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hiredis>=0:databases/py-hiredis@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack-python>=0:devel/py-msgpack-python@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

do-test: build
	@cd ${WRKSRC}/tests && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
