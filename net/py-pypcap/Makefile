PORTNAME=	pypcap
DISTVERSION=	1.2.3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplified object-oriented Python wrapper for libpcap

LICENSE=	BSD3CLAUSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent cython distutils

# PR 239725: workaround to avoid using /usr/lib32 over /usr/lib
LDFLAGS+=	-L/usr/lib

pre-configure:
	cd ${WRKSRC} && cython-${PYTHON_VER} pcap.pyx

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
