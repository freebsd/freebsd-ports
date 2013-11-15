# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	aescrypt
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}.0

PATCH_SITES=	http://devel.ringlet.net/security/aescrypt/patches/ \
		http://people.FreeBSD.org/~roam/ports/patches/security/aescrypt/
PATCHFILES=	aescrypt-0.7-roam-whopper-01.patch.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line AES encryption/decryption suite

GNU_CONFIGURE=	yes
MAKE_ENV+=	BINGRP=wheel

BINS=		aescrypt aesget

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
.for f in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
