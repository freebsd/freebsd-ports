# New ports collection makefile for:	lsh secure shell
# Date created:				29 MAY 2000
# Whom:					Eric Schwertfeger <eric@cybernut.com>
#
# $FreeBSD$

PORTNAME=	lsh
PORTVERSION=	1.5.1
CATEGORIES=	security ipv6
MASTER_SITES=	${MASTER_SITE_GNUPG} \
		ftp://ftp.lysator.liu.se/pub/security/%SUBDIR%/
MASTER_SITE_SUBDIR=	lsh lsh/old
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A secure (encrypted) remote shell compatible with ssh 2.0

BUILD_DEPENDS+=	${LOCALBASE}/include/gmp.h:${PORTSDIR}/math/libgmp4 \
		${LOCALBASE}/share/slib/require.scm:${PORTSDIR}/lang/slib
LIB_DEPENDS+=	oop:${PORTSDIR}/devel/liboop

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALL_TARGET=	install
CONFIGURE_ARGS+=	--with-include-path=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-lib-path=${LOCALBASE}/lib
LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS:S=""==}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
FIXME=		src/nettle/x86/aes.asm
.if defined(KRB5_HOME) && exists(${KRB5_HOME})
PLIST_SUB+=	KRB=""
.else
PLIST_SUB+=	KRB="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400014
CONFIGURE_ARGS+=	--without-ipv6
.endif

post-install:
.for BIN in lsh lsh-keygen lsh-writekey sexp-conv srp-gen lsh-decode-key
	strip ${PREFIX}/bin/${BIN}
.endfor
.for SBIN in lshd
	strip ${PREFIX}/sbin/${SBIN}
.endfor
.if !defined(NOPORTDOCS)
	install-info --section="Miscellaneous" \
		--entry="* LSH: (lsh).			lsh secure remote shell documentation." \
		${PREFIX}/info/lsh.info ${PREFIX}/info/dir
.endif

.include <bsd.port.post.mk>
