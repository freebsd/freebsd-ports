# New ports collection makefile for:	aescrypt
# Date created:		12 December 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	aescrypt
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://aescrypt.sourceforge.net/
MASTER_SITE_SUBDIR=aescrypt

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A command-line AES encryption/decryption suite

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/aescrypt
	${INSTALL_DATA} ${WRKSRC}/README.html ${PREFIX}/share/doc/aescrypt

.include <bsd.port.mk>
