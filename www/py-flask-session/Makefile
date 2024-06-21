PORTNAME=	flask-session
PORTVERSION=	0.8.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Server-side session support for Flask
WWW=		https://pythonhosted.org/Flask-Session/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachelib>=0.10.2:www/py-cachelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=2.2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgspec>=0.18.6:devel/py-msgspec@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

.include <bsd.port.mk>
