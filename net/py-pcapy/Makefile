# New ports collection makefile for:	pcapy
# Date created:				15th September 2005
# Whom:					Marcin Jessa <yazzy@yazzy.org>
# $FreeBSD$

PORTNAME=	pcapy
PORTVERSION=	0.10.4
CATEGORIES=	net python
MASTER_SITES=	http://oss.coresecurity.com/repo/ \
		http://www.yazzy.org/ports/pcapy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yazzy@yazzy.org
COMMENT=	Python extension module to capture packets on the network

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pcapy.so
PORTDOCS=	README LICENSE pcapy.html

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
LIB_DEPENDS+=	pcap.2:${PORTSDIR}/net/libpcap
PYDISTUTILS_BUILDARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib
.endif

.include <bsd.port.post.mk>
