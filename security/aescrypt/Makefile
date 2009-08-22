# New ports collection makefile for:	aescrypt
# Date created:		12 December 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	aescrypt
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}.0

PATCH_SITES=	http://devel.ringlet.net/security/aescrypt/patches/ \
		http://people.FreeBSD.org/~roam/ports/patches/security/aescrypt/
PATCHFILES=	aescrypt-0.7-roam-whopper-01.patch.gz

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A command-line AES encryption/decryption suite

GNU_CONFIGURE=	yes
MAKE_ENV+=	BINGRP=wheel

MAN1=		aescrypt.1 aesget.1
MANCOMPRESSED=	yes

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
