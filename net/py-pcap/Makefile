# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pcap
PORTVERSION=	0.6.6
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python interface to LBL Packet Capture library (libpcap)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Broken with python3 please consider using net/py-pypcap
EXPIRATION_DATE=2020-05-01

BUILD_DEPENDS=	swig3.0:devel/swig30

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	5u623l20
GH_PROJECT=	pylibpcap
GH_TAGNAME=	d442c3e
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	LIBPCAP

LIBPCAP_DESC=		Use the ports version of libpcap
LIBPCAP_LIB_DEPENDS=	libpcap.so.1:net/libpcap

post-patch-LIBPCAP-on:
	@${REINPLACE_CMD} -E -e 's|^(libpcap_dir[[:blank:]]*=).*$$|\1 "${LOCALBASE}/lib"|' \
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_pcapmodule.so

.include <bsd.port.mk>
