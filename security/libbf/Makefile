# Created by: Jim Geovedi <jim@corebsd.or.id>
# $FreeBSD$

PORTNAME=	libbf
PORTVERSION=	0.8.2b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.funet.fi/pub/mirrors/ftp.psy.uq.oz.au/libeay/ \
		ftp://ftp.psy.uq.oz.au/pub/Crypto/libeay/ \
		ftp://ftp.ntnu.no/pub/unix/security/ \
		ftp://ftp.sunsite.org.uk/Mirrors/ftp.psy.uq.oz.au/pub/Crypto/libeay/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	The Blowfish block cipher Library

BROKEN=		unfetchable

.if ${MACHINE_ARCH} == "i386"
MAKEFLAGS+=	BF_ENC=asm/bx86-elf.o
.else
MAKEFLAGS+=	BF_ENC=bf_enc.o
.endif

WRKSRC=		${WRKDIR}/bf

OPTIONS_DEFINE=	DOCS

PORTDOCS=	blowfish.doc COPYRIGHT README VERSION

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bfspeed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bftest ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libblowfish.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/blowfish.h ${STAGEDIR}${PREFIX}/include

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
