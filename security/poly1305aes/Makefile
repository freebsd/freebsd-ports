# New ports collection makefile for:	poly1305aes
# Date created:		18 February 2005
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	poly1305aes
PORTVERSION=	20050218
CATEGORIES=	security
MASTER_SITES=	http://cr.yp.to/mac/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	The poly1305 message authentication reference implementation using AES

USE_REINPLACE=	yes

MAKE_ENV+=	CC="${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${STRIP}"
ALL_TARGET=	default

REPLACE_HDRS=	aes.h cpucycles.h poly1305aes.h
PROGRAM_FILES=	poly1305aes-speed test-aes test-poly1305aes

do-install:
		${MKDIR} ${PREFIX}/include/poly1305
		${INSTALL_DATA} ${WRKSRC}/*_*.h ${PREFIX}/include/poly1305/
.for i in ${REPLACE_HDRS}
		${REINPLACE_CMD} -e "s,#include \",#include \"poly1305/," ${WRKSRC}/$i > ${WRKSRC}/$i.fixed
		${INSTALL_DATA} ${WRKSRC}/$i.fixed ${PREFIX}/include/poly1305/$i
		${INSTALL_DATA} ${WRKSRC}/*.a ${PREFIX}/lib/
		${INSTALL_DATA} ${PROGRAM_FILES:S,^,${WRKSRC}/,} ${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
