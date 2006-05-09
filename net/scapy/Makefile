# New ports collection makefile for:	scapy
# Date created:		08 dec 2005
# Whom:			vanhu <vanhu@netasq.com>
#
# $FreeBSD$
#
# TODO: - configurable --enable-xxx for various additional dependancies

PORTNAME=	scapy
PORTVERSION=	1.0.4
CATEGORIES=	net
MASTER_SITES=	http://secdev.org/projects/scapy/files/

MAINTAINER=	vanhu@netasq.com
COMMENT=	Powerful interactive packet manipulation program in python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dnet.so:${PORTSDIR}/net/py-libdnet \
		${PYTHON_SITELIBDIR}/pcap.py:${PORTSDIR}/net/py-pcap

MAN1=		scapy.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/scapy

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scapy.py ${PREFIX}/bin/scapy
	${INSTALL_MAN} ${WRKSRC}/scapy.1.gz ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
