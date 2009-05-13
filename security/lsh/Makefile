# New ports collection makefile for:	lsh secure shell
# Date created:				29 MAY 2000
# Whom:					Eric Schwertfeger <eric@cybernut.com>
#
# $FreeBSD$

PORTNAME=	lsh
PORTVERSION=	2.0.4
PORTREVISION=	3
CATEGORIES=	security ipv6
MASTER_SITES=	${MASTER_SITE_GNUPG} \
		ftp://ftp.lysator.liu.se/pub/security/%SUBDIR%/
MASTER_SITE_SUBDIR=	lsh lsh/old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A secure (encrypted) remote shell compatible with ssh 2.0

BUILD_DEPENDS+=	\
		${LOCALBASE}/share/guile/1.8/slibcat:${PORTSDIR}/lang/slib-guile
LIB_DEPENDS+=	oop:${PORTSDIR}/devel/liboop \
		gmp.8:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALL_TARGET=	install
CONFIGURE_ENV=	PREFIX="${PREFIX}" CC="${CC}" CFLAGS="${CFLAGS}"
CONFIGURE_ARGS+=	--with-include-path=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-lib-path=${LOCALBASE}/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
.if defined(KRB5_HOME) && exists(${KRB5_HOME})
PLIST_SUB+=	KRB=""
.else
PLIST_SUB+=	KRB="@comment "
.endif
.if defined(WITH_THREADS) || defined(WITH_LSH_THREADS)
LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS:S=""==}
.endif
MAN1=		lsftp.1 ssh-conv.1 lshg.1 lsh.1 lsh-writekey.1 lsh-upgrade.1 \
		lsh-upgrade-key.1 lsh-make-seed.1 lsh-keygen.1 \
		lsh-export-key.1 lsh-decrypt-key.1 lsh-decode-key.1 \
		lsh-authorize.1
MAN5=		secsh.5 SPKI.5 SHA.5 DSA.5
MAN8=		sftp-server.8 lshd.8
INFO=		lsh nettle

post-install:
.for BIN in lsh lsh-keygen lsh-writekey sexp-conv srp-gen lsh-decode-key
	${STRIP_CMD} ${PREFIX}/bin/${BIN}
.endfor
.for SBIN in lshd
	${STRIP_CMD} ${PREFIX}/sbin/${SBIN}
.endfor

test:
	(cd ${WRKSRC}/src/testsuite && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
