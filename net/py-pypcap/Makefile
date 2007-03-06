# New ports collection makefile for:	py-pypcap
# Date created:		15 Jul 2006
# Whom:			George V. Neville-Neil
#
# $FreeBSD$
#

PORTNAME=	pypcap
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://pypcap.googlecode.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnn@freebsd.org
COMMENT=	Simplified object-oriented Python extension module for libpcap

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex

USE_PYTHON=	yes
USE_PYTHON_PREFIX=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pcap.so

post-patch:
	${RM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pcap.c
.include <bsd.port.mk>
