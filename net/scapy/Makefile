# Created by: vanhu <vanhu@netasq.com>
# $FreeBSD$

PORTNAME=	scapy
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://secdev.org/projects/scapy/files/

MAINTAINER=	vanhu@FreeBSD.org
COMMENT=	Powerful interactive packet manipulation program in python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dnet.so:${PORTSDIR}/net/py-libdnet \
		${PYTHON_SITELIBDIR}/pcap.py:${PORTSDIR}/net/py-pcap

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	PYX PYCRYPTO PYGNUPLOT GRAPH P0F_BASE QUESO_BASE NMAP MANUF
PYX_DESC=	PostScript and PDF graphs drawing
PYCRYPTO_DESC=	Use py-crypto for WEP decoding
PYGNUPLOT_DESC=	Use py-gnuplot wrapper to plot graphs
GRAPH_DESC=	graph generation and visualization
P0F_BASE_DESC=	p0f OS signatures database
QUESO_BASE_DESC=	queso OS signatures database
NMAP_DESC=	nmap OS signatures database
MANUF_DESC=	wireshark's MANUF MAC database
SOX_DESC=	Support for VoIP

PYX_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyx/__init__.py:${PORTSDIR}/graphics/py-PyX
PYCRYPTO_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
PYGNUPLOT_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Gnuplot/__init__.py:${PORTSDIR}/math/py-gnuplot
GRAPH_RUN_DEPENDS=	${LOCALBASE}/bin/MagickCore-config:${PORTSDIR}/graphics/ImageMagick \
			${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz
P0F_BASE_RUN_DEPENDS=	${LOCALBASE}/etc/p0f/p0f.fp:${PORTSDIR}/net-mgmt/p0f
QUESO_BASE_RUN_DEPENDS=	${LOCALBASE}/etc/queso.conf.sample:${PORTSDIR}/net/queso
NMAP_RUN_DEPENDS=	${LOCALBASE}/share/nmap/nmap-os-db:${PORTSDIR}/security/nmap
MANUF_RUN_DEPENDS=	${LOCALBASE}/share/wireshark/manuf:${PORTSDIR}/net/wireshark
SOX_RUN_DEPENDS=	${LOCALBASE}/bin/sox:${PORTSDIR}/audio/sox

post-patch:
	@${REINPLACE_CMD} "s,share/man/man1,man/man1," ${WRKSRC}/setup.py
	@${REINPLACE_CMD} "s,/usr/share/,${LOCALBASE}/share/," \
		${WRKSRC}/scapy/data.py ${WRKSRC}/scapy/utils6.py \
		${WRKSRC}/scapy/modules/nmap.py
	@${REINPLACE_CMD} "s,/etc/,${LOCALBASE}/etc/," \
		${WRKSRC}/scapy/modules/p0f.py ${WRKSRC}/scapy/modules/queso.py

.include <bsd.port.mk>
