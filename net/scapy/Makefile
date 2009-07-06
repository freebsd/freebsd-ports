# New ports collection makefile for:	scapy
# Date created:		08 dec 2005
# Whom:			vanhu <vanhu@netasq.com>
#
# $FreeBSD$
#
# TODO: - configurable --enable-xxx for various additional dependancies

PORTNAME=	scapy
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://secdev.org/projects/scapy/files/

MAINTAINER=	vanhu@netasq.com
COMMENT=	Powerful interactive packet manipulation program in python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dnet.so:${PORTSDIR}/net/py-libdnet \
		${PYTHON_SITELIBDIR}/pcap.py:${PORTSDIR}/net/py-pcap

MAN1=		scapy.1
MANCOMPRESSED=	yes

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes

OPTIONS=	PYX "Support for PostScript and PDF graphs drawing" off \
		PYCRYPTO "Support for py-crypto for WEP decoding" off \
		PYGNUPLOT "Support for py-gnuplot wrapper to plot graphs" off \
		GRAPH	"Support for graph generation and visualization" off \
		P0F_BASE "Support for p0f OS signatures database" off \
		QUESO_BASE "Support for queso OS signatures database" off \
		NMAP "Support for nmap OS signatures database" off \
		MANUF "Support for wireshark's MANUF MAC database" off \
		VPYTHON "Support for 3D representation of traceroute" off \
		SOX "Support for VoIP" off

.include <bsd.port.pre.mk>

.if defined(WITH_PYX)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pyx/__init__.py:${PORTSDIR}/graphics/py-PyX
.endif

.if defined(WITH_PYCRYPTO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
.endif

.if defined(WITH_PYGNUPLOT)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Gnuplot/__init__.py:${PORTSDIR}/math/py-gnuplot
.endif

.if defined(WITH_GRAPH)
RUN_DEPENDS+=	${LOCALBASE}/bin/MagickCore-config:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz
.endif

.if defined(WITH_P0F_BASE)
RUN_DEPENDS+=	${LOCALBASE}/etc/p0f/p0f.fp:${PORTSDIR}/net-mgmt/p0f
.endif

.if defined(WITH_QUESO_BASE)
RUN_DEPENDS+=	${LOCALBASE}/etc/queso.conf.sample:${PORTSDIR}/net/queso
.endif

.if defined(WITH_NMAP)
RUN_DEPENDS+=	${LOCALBASE}/share/nmap/nmap-os-db:${PORTSDIR}/security/nmap
.endif

.if defined(WITH_MANUF)
RUN_DEPENDS+=	${LOCALBASE}/share/wireshark/manuf:${PORTSDIR}/net/wireshark
.endif

.if defined(WITH_VPYTHON)
RUN_DEPENDS+=	${LOCALBASE}/bin/vpython:${PORTSDIR}/graphics/py-visual
.endif

.if defined(WITH_SOX)
RUN_DEPENDS+=	${LOCALBASE}/bin/sox:${PORTSDIR}/audio/sox
.endif

SCAPY_MODULES=	nmap.py p0f.py queso.py

post-patch:
	@${REINPLACE_CMD} "s,share/man/man1,man/man1," ${WRKSRC}/setup.py
	@${REINPLACE_CMD} "s,%%LOCALBASE%%,${LOCALBASE}," \
		${SCAPY_MODULES:S,^,${WRKSRC}/scapy/modules/,} \
		${WRKSRC}/scapy/config.py \
		${WRKSRC}/scapy/utils6.py

.include <bsd.port.post.mk>
