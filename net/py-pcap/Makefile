# New ports collection makefile for:	py-pcap
# Date created:		24 Nov 2001
# Whom:			Hye-Shik Chang <perky@fallin.lv>
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

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig11

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

PCAPTEST!=	grep PCAP_IF_LOOPBACK /usr/include/pcap.h || true
.if empty(PCAPTEST)
BROKEN=		"needs libpcap 0.7 or higher"
.endif

.include <bsd.port.mk>
