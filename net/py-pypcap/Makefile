# Created by: George V. Neville-Neil
# $FreeBSD$

PORTNAME=	pypcap
DISTVERSIONPREFIX=	${PORTNAME:tu}_
DISTVERSION=	1_1
PORTREVISION=	6
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Simplified object-oriented Python extension module for libpcap

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyrex>0:devel/pyrex@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dugsong

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-patch:
	@${RM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pcap.c

pre-build:
	(cd ${WRKSRC}; pyrexc pcap.pyx)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pcap.so

.include <bsd.port.mk>
