# Created by: vanhu <vanhu@netasq.com>
# $FreeBSD$
#
# TODO: - configurable --enable-xxx for various additional dependancies

PORTNAME=	scapy
PORTVERSION=	2.2.0
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

OPTIONS_DEFINE=	PYX PYCRYPTO PYGNUPLOT GRAPH P0F_BASE QUESO_BASE MMAP MANUF
PYX_DESC=	PostScript and PDF graphs drawing
PYCRYPTO_DESC=	Use py-crypto for WEP decoding
PYGNUPLOT_DESC=	Use py-gnuplot wrapper to plot graphs
GRAPH_DESC=	graph generation and visualization
P0F_BASE_DESC=	p0f OS signatures database
QUESO_BASE_DESC=	queso OS signatures database
NMAP_DESC=	nmap OS signatures database
MANUF_DESC=	wireshark's MANUF MAC database
SOX_DESC=	Support for VoIP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYX}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pyx/__init__.py:${PORTSDIR}/graphics/py-PyX
.endif

.if ${PORT_OPTIONS:MPYCRYPTO}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
.endif

.if ${PORT_OPTIONS:MPYGNUPLOT}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Gnuplot/__init__.py:${PORTSDIR}/math/py-gnuplot
.endif

.if ${PORT_OPTIONS:MGRAPH}
RUN_DEPENDS+=	${LOCALBASE}/bin/MagickCore-config:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz
.endif

.if ${PORT_OPTIONS:MP0F_BASE}
RUN_DEPENDS+=	${LOCALBASE}/etc/p0f/p0f.fp:${PORTSDIR}/net-mgmt/p0f
.endif

.if ${PORT_OPTIONS:MQUESO_BASE}
RUN_DEPENDS+=	${LOCALBASE}/etc/queso.conf.sample:${PORTSDIR}/net/queso
.endif

.if ${PORT_OPTIONS:MNMAP}
RUN_DEPENDS+=	${LOCALBASE}/share/nmap/nmap-os-db:${PORTSDIR}/security/nmap
.endif

.if ${PORT_OPTIONS:MMANUF}
RUN_DEPENDS+=	${LOCALBASE}/share/wireshark/manuf:${PORTSDIR}/net/wireshark
.endif

.if ${PORT_OPTIONS:MSOX}
RUN_DEPENDS+=	${LOCALBASE}/bin/sox:${PORTSDIR}/audio/sox
.endif

post-patch:
	@${REINPLACE_CMD} "s,share/man/man1,man/man1," ${WRKSRC}/setup.py
	@${REINPLACE_CMD} "s,/usr/share/,${LOCALBASE}/share/," \
		${WRKSRC}/scapy/data.py ${WRKSRC}/scapy/utils6.py \
		${WRKSRC}/scapy/modules/nmap.py
	@${REINPLACE_CMD} "s,/etc/,${LOCALBASE}/etc/," \
		${WRKSRC}/scapy/modules/p0f.py ${WRKSRC}/scapy/modules/queso.py

.include <bsd.port.mk>
