# New ports collection makefile for:	py-pcap
# Date created:		24 Nov 2001
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	pcap
PORTVERSION=	0.4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pylibpcap
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylibpcap-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python interface to LBL Packet Capture library (libpcap)

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig11

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 460001 || \
	( ${OSVERSION} >= 500000 && ${OSVERSION} < 500038 )
IGNORE=		"needs libpcap 0.7 or higher"
.endif

.include <bsd.port.post.mk>
