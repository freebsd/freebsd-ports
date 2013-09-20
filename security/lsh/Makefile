# Created by: Eric Schwertfeger <eric@cybernut.com>
# $FreeBSD$

PORTNAME=	lsh
PORTVERSION=	2.0.4
PORTREVISION=	5
CATEGORIES=	security ipv6
MASTER_SITES=	${MASTER_SITE_GNUPG} \
		ftp://ftp.lysator.liu.se/pub/security/%SUBDIR%/
MASTER_SITE_SUBDIR=	lsh lsh/old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure (encrypted) remote shell compatible with ssh 2.0

LIB_DEPENDS=	oop:${PORTSDIR}/devel/liboop \
		gmp.10:${PORTSDIR}/math/gmp

USE_CSTD=	c89
GNU_CONFIGURE=	yes
USE_XORG=	xau
USE_GMAKE=	yes
INSTALL_TARGET=	install
CONFIGURE_ENV=	PREFIX="${PREFIX}"
CONFIGURE_ARGS+=	--with-include-path=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-lib-path=${LOCALBASE}/lib
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

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e "s|M4)|M4) -g|g" ${WRKSRC}/src/nettle/Makefile.in

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
PLIST_SUB+=	KRB=""
.else
PLIST_SUB+=	KRB="@comment "
.endif

.include <bsd.port.post.mk>
