PORTNAME=	pyenet
DISTVERSION=	1.3.13.post7
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd@skinc.ru
COMMENT=	Python wrapper for the ENet library by Lee Salzman
WWW=		https://pypi.python.org/pypi/pyenet

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/enet/LICENSE

USES=		python
USE_PYTHON=	autoplist cython distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/enet*.so

.include <bsd.port.mk>
