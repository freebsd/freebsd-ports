# Created by: George V. Neville-Neil
# $FreeBSD$

PORTNAME=	pypcap
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Simplified object-oriented Python extension module for libpcap

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pcap

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pcap.so

NO_STAGE=	yes
post-patch:
	@${RM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pcap.c

pre-build:
	(cd ${WRKSRC}; pyrexc pcap.pyx)

.include <bsd.port.mk>
