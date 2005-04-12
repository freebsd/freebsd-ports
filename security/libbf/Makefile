# New ports collection makefile for:	libbf
# Date created:				Sep 30, 2002
# Whom:					Jim Geovedi <jim@corebsd.or.id>
#
# $FreeBSD$
#

PORTNAME=	libbf
PORTVERSION=	0.8.2b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.funet.fi/pub/mirrors/ftp.psy.uq.oz.au/libeay/ \
		ftp://ftp.psy.uq.oz.au/pub/Crypto/libeay/ \
		ftp://ftp.ntnu.no/pub/unix/security/ \
		ftp://ftp.sunsite.org.uk/Mirrors/ftp.psy.uq.oz.au/pub/Crypto/libeay/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	The Blowfish block cipher Library

.if ${MACHINE_ARCH} == "i386"
MAKEFLAGS+=	BF_ENC=asm/bx86-elf.o
.else
MAKEFLAGS+=	BF_ENC=bf_enc.o
.endif

WRKSRC=		${WRKDIR}/bf

MYPORTDOCS=	blowfish.doc COPYRIGHT README VERSION

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bfspeed ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bftest ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libblowfish.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/blowfish.h ${PREFIX}/include

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
