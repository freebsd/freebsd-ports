# Created by: Ju Pengfei <jupengfei@gmail.com>

PORTNAME=	psutil
PORTVERSION=	5.9.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Process utilities module for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}psutil121

CPE_VENDOR=	psutil_project

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
