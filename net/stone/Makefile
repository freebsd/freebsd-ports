# New ports collection makefile for:	stone
# Date created:		25 April 2001
# Whom:			Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	stone
PORTVERSION=	2.1d
CATEGORIES=	net
MASTER_SITES=	http://www.gcd.org/sengoku/stone/

MAINTAINER=	mistral@imasy.or.jp

MAN1=		${PORTNAME}.1
MANLANG=	"" ja

.include <bsd.port.pre.mk>

pre-patch:
.if exists(/usr/bin/openssl)
ALL_TARGET=	bsd-ssl
EXTRA_PATCHES=	${FILESDIR}/base.patch
.elif exists(${PREFIX}/bin/openssl)
ALL_TARGET=	bsd-ssl
EXTRA_PATCHES=	${FILESDIR}/ports.patch
.else
ALL_TARGET=	bsd-pop
	@${ECHO} "You can build stone with SSL support by installing OpenSSL."
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stone ${PREFIX}/bin/stone
	${INSTALL_MAN} ${WRKSRC}/stone.1 ${PREFIX}/man/man1/stone.1
	${INSTALL_MAN} ${WRKSRC}/stone.1.ja ${PREFIX}/man/ja/man1/stone.1

.include <bsd.port.post.mk>
