# New ports collection makefile for:	lsh secure shell
# Date created:				29 MAY 2000
# Whom:					Eric Schwertfeger <eric@cybernut.com>
#
# $FreeBSD$

PORTNAME=	lsh
PORTVERSION=	0.9.11
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/security/lsh/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	eric@cybernut.com

RESTRICTED=	"Crypto; export-controlled"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400014
CONFIGURE_ARGS+=--without-ipv6
.endif

post-install:
.for BIN in lsh lsh_keygen lsh_writekey sexp_conv srp-gen
	strip ${PREFIX}/bin/${BIN}
.endfor
.for SBIN in lshd lsh_proxy
	strip ${PREFIX}/sbin/${SBIN}
.endfor
.if !defined(NOPORTDOCS)
	install-info --section="Miscellaneous" \
		--entry="* LSH: (lsh).			lsh secure remote shell documentation." \
		${PREFIX}/info/lsh.info ${PREFIX}/info/dir
.endif

.include <bsd.port.post.mk>
