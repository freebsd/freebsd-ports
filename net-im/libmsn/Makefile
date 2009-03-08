# ex:ts=8
# Ports collection makefile for:	libmsn
# Date created:			Feb 6, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libmsn
DISTVERSION=	4.0-beta4
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	decept0@gmail.com
COMMENT=	A library for connecting to MSN Messenger service

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
