# Created by: vanhu <vanhu@netasq.com>
# $FreeBSD$

PORTNAME=	scapy
PORTVERSION=	2.4.3
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Powerful interactive packet manipulation program in python

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libdnet>0:net/py-libdnet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypcap>0:net/py-pypcap@${PY_FLAVOR}

USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	GRAPH IPYTHON P0F_BASE MANUF MATPLOT NMAP PYCRYPTO PYGNUPLOT PYX QUESO_BASE SOX
GRAPH_DESC=	graph generation and visualization
IPYTHON_DESC=	Use IPython (enhanced interactive shell)
MANUF_DESC=	wireshark's MANUF MAC database
MATPLOT_DESC=	Install python matplotlibs
NMAP_DESC=	nmap OS signatures database
P0F_BASE_DESC=	p0f OS signatures database
PYCRYPTO_DESC=	Use py-crypto for WEP decoding
PYGNUPLOT_DESC=	Use py-gnuplot wrapper to plot graphs
PYX_DESC=	PostScript and PDF graphs drawing
QUESO_BASE_DESC=queso OS signatures database
SOX_DESC=	Support for VoIP

GRAPH_RUN_DEPENDS=	${LOCALBASE}/bin/MagickCore-config:graphics/ImageMagick6 \
			${LOCALBASE}/bin/dot:graphics/graphviz
NMAP_RUN_DEPENDS=	${LOCALBASE}/share/nmap/nmap-os-db:security/nmap
MANUF_RUN_DEPENDS=	${LOCALBASE}/share/wireshark/manuf:net/wireshark
MATPLOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}
P0F_BASE_RUN_DEPENDS=	${LOCALBASE}/etc/p0f.fp:net-mgmt/p0f
PYCRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR}
PYGNUPLOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gnuplot>0:math/py-gnuplot@${PY_FLAVOR}
PYX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyX>0:graphics/py-PyX@${PY_FLAVOR}
QUESO_BASE_RUN_DEPENDS=	${LOCALBASE}/etc/queso.conf.sample:net/queso
SOX_RUN_DEPENDS=	${LOCALBASE}/bin/sox:audio/sox

PYX_PREVENTS=	PYGNUPLOT
PYX_PREVENTS_MSG=	PyX requires Python 3.4+ and py-gnuplot requires 2.7.

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYGNUPLOT}
USES+=		python:2.7
.elif ${PORT_OPTIONS:MPYX}
USES+=		python:3.4+
.else
USES+=		python
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIPYTHON}
.if ${FLAVOR:Mpy27}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipython5>0:devel/ipython5@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR}
.endif
.endif

post-patch:
	@${REINPLACE_CMD} "s,share/man/man1,man/man1," ${WRKSRC}/setup.py
	@${REINPLACE_CMD} "s,pdflatex,pdftex," ${WRKSRC}/scapy/extlib.py
	@${REINPLACE_CMD} "s,/usr/share/,${LOCALBASE}/share/," \
		${WRKSRC}/scapy/data.py \
		${WRKSRC}/scapy/modules/nmap.py \
	       	${WRKSRC}/scapy/utils6.py
	@${REINPLACE_CMD} "s,/etc/,${LOCALBASE}/etc/," \
		${WRKSRC}/scapy/modules/p0f.py

.include <bsd.port.post.mk>
