# New ports collection makefile for:	py-pcap
# Date created:		24 Nov 2001
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	pcap
PORTVERSION=	0.3.1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pylibpcap
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylibpcap-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/SWIG

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
