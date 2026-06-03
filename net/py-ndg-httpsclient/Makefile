PORTNAME=	ndg-httpsclient
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ndg_httpsclient-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enhance HTTPS support for httplib and urllib2
WWW=		https://github.com/cedadev/ndg_httpsclient

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/ndg/httpsclient/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.4:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>=0.13,1:security/py-pyopenssl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
