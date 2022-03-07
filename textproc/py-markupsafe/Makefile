# Created by: wen@FreeBSD.org

PORTNAME=	markupsafe
PORTVERSION=	2.1.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MarkupSafe-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implements XML/HTML/XHTML Markup safe string for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
