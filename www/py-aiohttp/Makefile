# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aiohttp
PORTVERSION=	0.8.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	HTTP client/server for asyncio

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=		TESTS
TESTS_DESC=		Install tools for test suite
TESTS_BUILD_DEPENDS=	${RUN_DEPENDS} \
			${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose \
			${PYTHON_PKGNAMEPREFIX}gunicorn>0:${PORTSDIR}/www/py-gunicorn

USE_PYTHON=		3.3+
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 340
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}asyncio>0:${PORTSDIR}/devel/py-asyncio
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.post.mk>
