PORTNAME=	pysendfile
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	net python devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python interface to sendfile(2)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	py*-sendfile

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sendfile*.so

.include <bsd.port.mk>
