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

LICENSE=	BSD

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
