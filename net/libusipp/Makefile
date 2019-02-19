# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libusipp
PORTVERSION=	2.24
DISTVERSIONPREFIX=	libusipp-
DISTVERSIONSUFFIX=	s
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unix socket interface for C++ raw IP/IP6/UDP/TCP, layer 2 framework

LICENSE=	GPLv3+

USES=		autoreconf compiler:c++11-lang gmake

GNU_CONFIGURE=	yes
WRKSRC_SUBDIR=	src
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	stealth

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/usi++ ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/../usi++/*.h ${STAGEDIR}${PREFIX}/include/usi++
	${INSTALL_DATA} ${WRKSRC}/libusi++.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libusi++.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
