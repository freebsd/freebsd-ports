# New ports collection makefile for:	gnupg
# http://www.gnupg.org/
# Version required:	1.0.0
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	gnupg-1.0.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.guug.de/pub/gcrypt/gnupg/ \
		ftp://pgp.iijlab.net/pub/gnupg/gnupg/ \
		ftp://ftp.win.or.jp/pub/network/gnupg/gnupg/

MAINTAINER=	kuriyama@FreeBSD.org

RESTRICTED=	"Crypto; export-controlled"
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-included-gettext
MAN1=		gpg.1
MLINKS=		gpg.1 gpgm.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
CONFIGURE_ARGS+=--disable-asm
.endif
CFLAGS:=	${CFLAGS:S/-pipe//g}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gnupg
.for i in DETAILS FAQ HACKING OpenPGP
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/gnupg
.endfor
.for i in ABOUT-NLS AUTHORS BUGS COPYING INSTALL NEWS PROJECTS \
	README THANKS TODO VERSION
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/gnupg
.endfor
.endif
#	${CHMOD} u+s ${PREFIX}/bin/gpg

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.post.mk>
