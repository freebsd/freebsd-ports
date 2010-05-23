# New ports collection makefile for:	py-pcap
# Date created:		24 Nov 2001
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	pcap
PORTVERSION=	0.6.2
CATEGORIES=	net python
MASTER_SITES=	SF/pylib${PORTNAME}/pylib${PORTNAME}/${PORTVERSION} \
		http://people.freebsd.org/~perky/distfiles/:local

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylibpcap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to LBL Packet Capture library (libpcap)

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	pylibpcap

.include <bsd.port.mk>
