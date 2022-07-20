PORTNAME=	ndg-httpsclient
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ndg_httpsclient-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enhance HTTPS support for httplib and urllib2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/ndg/httpsclient/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.4:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.13:security/py-openssl@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
