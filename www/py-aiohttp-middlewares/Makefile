PORTNAME=	aiohttp-middlewares
PORTVERSION=	3.0.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	aiohttp_middlewares-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of useful middlewares for aiohttp applications
WWW=		https://aiohttp-middlewares.readthedocs.io/en/stable/ \
		https://github.com/playpauseandstop/aiohttp-middlewares

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.11.0<4.0.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.17.0<2.0.0:www/py-yarl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SOURCE_DATE_EPOCH=315532800 # 1980-01-01 00:00:00 UTC
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}async_timeout>=4.0.2<6.0.0:devel/py-async_timeout@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
