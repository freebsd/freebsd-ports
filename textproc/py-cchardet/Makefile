PORTNAME=	cchardet
PORTVERSION=	2.1.7
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High speed universal character encoding detector
WWW=		https://github.com/PyYoshi/cChardet

LICENSE=	GPLv2 LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:indirect python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
