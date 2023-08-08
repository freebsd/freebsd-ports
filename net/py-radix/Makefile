PORTNAME=	radix
PORTVERSION=	0.10.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	lerik@nolink.net
COMMENT=	Python radix-tree implementation
WWW=		https://github.com/mjschultz/py-radix

LICENSE=	ISCL BSD4CLAUSE
LICENSE_COMB=	dual

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_${PORTNAME}*.so

.include <bsd.port.mk>
