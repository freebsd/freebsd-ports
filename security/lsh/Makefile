# New ports collection makefile for:	lsh secure shell
# Date created:				29 MAY 2000
# Whom:					Eric Schwertfeger <eric@cybernut.com>
#
# $FreeBSD$

PORTNAME=	lsh
PORTVERSION=	1.0
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/security/lsh/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

RESTRICTED=	"Crypto; export-controlled"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400014
CONFIGURE_ARGS+=--without-ipv6
.endif

MAN1=	lsh_writekey.1 lsh_keygen.1 lsh.1
MAN5=	DSA.5 secsh.5 SHA.5 SPKI.5
MAN8=	lshd.8

post-install:
.for BIN in lsh lsh_keygen lsh_writekey sexp-conv srp-gen lsh-decode-key
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
