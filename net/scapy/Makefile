# New ports collection makefile for:	scapy
# Date created:		08 dec 2005
# Whom:			vanhu <vanhu@netasq.com>
#
# $FreeBSD$
#
# TODO: - configurable --enable-xxx for various additional dependancies

PORTNAME=	scapy
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://secdev.org/projects/scapy/files/

MAINTAINER=	vanhu@netasq.com
COMMENT=	Powerful interactive packet manipulation program in python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dnet.so:${PORTSDIR}/net/py-libdnet \
		${PYTHON_SITELIBDIR}/pcap.py:${PORTSDIR}/net/py-pcap

MAN1=		scapy.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/scapy

USE_PYTHON=	yes
NO_BUILD=	yes

OPTIONS=	PYX "Support for PostScript and PDF graphs drawing" off \
		PYCRYPTO "Support for py-crypto for WEP decoding" off \
		PYGNUPLOT "Support for py-gnuplot wrapper to plot graphs" off \
		P0F_BASE "Support for p0f OS signatures database" off \
		QUESO_BASE "Support for queso OS signatures database" off \
		NMAP "Support for nmap OS signatures database" off \
		MANUF "Support for wireshark's MANUF MAC database" off

.include <bsd.port.pre.mk>

.if defined(WITH_PYX)
RUN_DEPENDS+=	 ${PYTHON_SITELIBDIR}/pyx/__init__.py:${PORTSDIR}/graphics/py-PyX
.endif

.if defined(WITH_PYCRYPTO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
.endif

.if defined(WITH_PYGNUPLOT)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Gnuplot/__init__.py:${PORTSDIR}/math/py-gnuplot
.endif

.if defined(WITH_P0F_BASE)
RUN_DEPENDS+=	${PREFIX}/etc/p0f/p0f.fp:${PORTSDIR}/net-mgmt/p0f
.endif

.if defined(WITH_QUESO_BASE)
RUN_DEPENDS+=	${PREFIX}/etc/queso.conf:${PORTSDIR}/net/queso
.endif

.if defined(WITH_NMAP)
RUN_DEPENDS+=	${PREFIX}/share/nmap/nmap-os-fingerprints:${PORTSDIR}/security/nmap
.endif

.if defined(WITH_MANUF)
RUN_DEPENDS+=	${PREFIX}/share/wireshark/manuf:${PORTSDIR}/net/wireshark
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scapy.py ${PREFIX}/bin/scapy
	${INSTALL_MAN} ${WRKSRC}/scapy.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
