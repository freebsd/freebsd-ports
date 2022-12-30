PORTNAME=	psutil
PORTVERSION=	5.9.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Process utilities module for Python
WWW=		https://github.com/giampaolo/psutil

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe python:3.6+
USE_PYTHON=	autoplist concurrent distutils

LDFLAGS+=	-lutil

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}psutil121

CPE_VENDOR=	psutil_project

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
