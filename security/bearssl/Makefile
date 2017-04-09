# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bearssl
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	https://bearssl.org/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Implementation of TLS/SSL in C

LICENSE=	MIT

MAKE_ARGS=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS} -fPIC" LDDLL="${CC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/brssl ${STAGEDIR}${LOCALBASE}/bin/
	${INSTALL_LIB} ${WRKSRC}/build/libbearssl.so ${STAGEDIR}${LOCALBASE}/lib/
	(cd ${WRKSRC}/inc && ${COPYTREE_SHARE} \* ${STAGEDIR}${LOCALBASE}/include)

.include <bsd.port.mk>
