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
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pylib${PORTNAME}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_pcapmodule.so \
		%%PYTHON_SITELIBDIR%%/pcap.py \
		%%PYTHON_SITELIBDIR%%/pcap.pyc \
		%%PYTHON_SITELIBDIR%%/pcap.pyo

NO_STAGE=	yes
.include <bsd.port.mk>
