# ex:ts=8
# Ports collection makefile for:	py-libnet
# Date created:			Jan 30, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	libnet
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pylibnet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylibnet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module for the libnet packet construction library

BUILD_DEPENDS=	${LOCALBASE}/bin/swig1.1:${PORTSDIR}/devel/swig11 \
		${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAKE_ARGS=	SWIG=${LOCALBASE}/bin/swig1.1 \
		LIBNET_INCLUDES=-I${LOCALBASE}/include \
		PYTHON_INCLUDES=-I${PYTHON_INCLUDEDIR} \
		CFLAGS="${CFLAGS} `libnet-config --defines` -fPIC" \
		LIBNET_LIB=${LOCALBASE}/lib/libnet.a \
		CC=${CC}

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/libnet.py \
		lib/%%PYTHON_VERSION%%/site-packages/libnetcmodule.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64 (tries to link non-PIC libnet.a into PIC shared library)"
.endif

do-install:
.for file in libnet.py libnetcmodule.so
	${INSTALL_DATA} ${WRKSRC}/${file} ${PYTHON_SITELIBDIR}
.endfor

.include <bsd.port.post.mk>
