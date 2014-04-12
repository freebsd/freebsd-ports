# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	psutil
PORTVERSION=	2.1.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Process utilities module for Python

LICENSE=	BSD3CLAUSE

PYDISTUTILS_AUTOPLIST=	yes
USE_PYDISTUTILS=yes
USE_PYTHON=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_psutil_bsd.so ${STAGEDIR}${PYTHON_SITELIBDIR}/_psutil_posix.so

.include <bsd.port.mk>
