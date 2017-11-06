# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	ndg_httpsclient
PORTVERSION=	0.4.3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP/source/n/ndg-httpsclient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enhance HTTPS support for httplib and urllib2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/ndg/httpsclient/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.4:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.13:security/py-openssl

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
