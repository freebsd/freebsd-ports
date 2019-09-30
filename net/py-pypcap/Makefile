# Created by: George V. Neville-Neil
# $FreeBSD$

PORTNAME=	pypcap
DISTVERSION=	1.2.3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplified object-oriented Python wrapper for libpcap

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	autoplist cython distutils

# Add workaround to avoid using /usr/lib32 over /usr/lib
# See PR/239725 for details
LDFLAGS+=	-L/usr/lib

pre-configure:
	cd ${WRKSRC} && cython-${PYTHON_VER} pcap.pyx

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pcap.so

.include <bsd.port.mk>
