PORTNAME=	requests-gssapi
PORTVERSION=	1.4.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/-/_/}-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GSSAPI authentication handler for python-requests
WWW=		https://pypi.org/project/requests-gssapi/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gssapi>=1.4.1:security/py-gssapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=1.1.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
