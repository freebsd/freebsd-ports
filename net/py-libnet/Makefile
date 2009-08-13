# ex:ts=8
# Ports collection makefile for:	py-libnet
# Date created:			Jan 30, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	libnet
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	pylibnet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylibnet-${PORTVERSION}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Python module for the libnet packet construction library

BUILD_DEPENDS=	${LOCALBASE}/bin/swig1.3:${PORTSDIR}/devel/swig13 \
		${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
WRKEXAMPLE=	${WRKDIR}/${DISTNAME}/samples

MAKE_ARGS=	SWIG=${LOCALBASE}/bin/swig1.3 \
		LIBNET_INCLUDES=-I${LOCALBASE}/include \
		PYTHON_INCLUDES=-I${PYTHON_INCLUDEDIR} \
		CFLAGS="${CFLAGS} `${LIBNET_CONFIG} --defines` `${LIBNET_CONFIG} --cflags` -fPIC" \
		LIBNET_LIB="`${LIBNET_CONFIG} --libs`" \
		CC=${CC}

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

EXAMPLESFILES=	test-libnet-icmp-echo-req.py test-libnet-tcp-syn.py test-libnet-arp-req.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Does not compile on amd64 (tries to link non-PIC libnet.a into PIC shared library)
.endif

post-patch:
	${REINPLACE_CMD} -e 's,^const ,%constant ,' ${WRKSRC}/constants.i

post-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}
	${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
.for f in libnet.py libnet.pyc libnet.pyo _libnet.so
	${INSTALL_DATA} ${WRKSRC}/${f} ${PYTHON_SITELIBDIR}
.endfor
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLESFILES}
	${INSTALL_DATA} ${WRKEXAMPLE}/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
