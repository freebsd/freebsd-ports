# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	poly1305aes
PORTVERSION=	20050218
CATEGORIES=	security
MASTER_SITES=	http://cr.yp.to/mac/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Poly1305 message authentication reference implementation using AES

LICENSE=	PD

ALL_TARGET=	default

CC+=		${CPPFLAGS} ${CFLAGS} ${LDFLAGS}

BROKEN_aarch64=		Fails to build: poly1305aes.impl.do: fatal: all tests failed
NOT_FOR_ARCHS=	amd64

.include <bsd.port.pre.mk>

pre-build:
.if ${ARCH} == "i386"
	@${ECHO_CMD} "ppro" > ${WRKSRC}/poly1305aes.impl
.endif

post-build:
.for i in aes.h cpucycles.h poly1305aes.h
	@${REINPLACE_CMD} -e \
		's|#include "|#include "poly1305/|' ${WRKSRC}/${i}
.endfor

do-install:
.for i in poly1305aes-speed test-aes test-poly1305aes
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} \
		${STAGEDIR}${PREFIX}/bin)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/poly1305
	(cd ${WRKSRC} && ${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/poly1305)
	(cd ${WRKSRC} && ${INSTALL_DATA} *.a \
		${STAGEDIR}${PREFIX}/lib)

.include <bsd.port.post.mk>
