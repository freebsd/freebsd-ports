# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pcap
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	SF/pylib${PORTNAME}/pylib${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylib${PORTNAME}-${PORTVERSION}

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Python interface to LBL Packet Capture library (libpcap)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	LIBPCAP

LIBPCAP_DESC=		Use the ports version of libpcap
LIBPCAP_LIB_DEPENDS=	libpcap.so.1:net/libpcap

post-patch-LIBPCAP-on:
	@${REINPLACE_CMD} -E -e 's|^(libpcap_dir[[:blank:]]*=).*$$|\1 "${LOCALBASE}/lib"|' \
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_pcapmodule.so

.include <bsd.port.mk>
