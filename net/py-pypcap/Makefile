# New ports collection makefile for:	py-pypcap
# Date created:		15 Jul 2006
# Whom:			George V. Neville-Neil
#
# $FreeBSD$
#

PORTNAME=	pypcap
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tmclaugh@FreeBSD.org
COMMENT=	Simplified object-oriented Python extension module for libpcap

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex

USE_PYTHON=	yes
USE_PYTHON_PREFIX=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGNAME=	pcap

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pcap.so

post-patch:
	${RM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pcap.c

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800074
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
