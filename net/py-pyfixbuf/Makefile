PORTNAME=	pyfixbuf
PORTVERSION=	0.8.1
CATEGORIES=	net python
MASTER_SITES=	https://tools.netsa.cert.org/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python API for libfixbuf

LICENSE=	GPLR LGPL21
LICENSE_COMB=	multi
LICENSE_NAME_GPLR=	Government Purpose License Rights
LICENSE_FILE_GPLR=	${WRKSRC}/LICENSE-OPENSOURCE.txt
LICENSE_PERMS_GPLR=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfixbuf.so:net/libfixbuf

USES=		pkgconfig python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
