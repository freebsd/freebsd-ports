PORTNAME=	pyipp
DISTVERSION=	0.17.2
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Asynchronous Python client for Internet Printing Protocol (IPP)
WWW=		https://github.com/ctalkington/python-ipp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.0.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}awesomeversion>=21.10.1:devel/py-awesomeversion@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}backoff>=2.2.0:devel/py-backoff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deepmerge>=1.1.0:devel/py-deepmerge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.6:www/py-yarl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes
NO_TEST=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}async_timeout>=5.0.1:devel/py-async_timeout@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
