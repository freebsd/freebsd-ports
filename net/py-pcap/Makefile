# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pcap
PORTVERSION=	0.6.4
CATEGORIES=	net python
MASTER_SITES=	SF/pylib${PORTNAME}/pylib${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylib${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to LBL Packet Capture library (libpcap)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig:devel/swig13

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_pcapmodule.so

.include <bsd.port.mk>
