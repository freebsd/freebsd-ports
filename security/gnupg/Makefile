# New ports collection makefile for:	gnupg
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	1.0.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/gnupg/ \
		ftp://pgp.iijlab.net/pub/gnupg/ \
		ftp://ring.aist.go.jp/pub/net/gnupg/gnupg/
DISTFILES=	${DISTNAME}.tar.gz gpg.1.gz
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	kuriyama@FreeBSD.org

RESTRICTED=	"Crypto; export-controlled"
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-included-gettext
MAN1=		gpg.1
MLINKS=		gpg.1 gpgm.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
USE_GMAKE=	YES
.endif
CFLAGS:=	${CFLAGS:S/-pipe//g}

post-extract:
	${GZIP_CMD} -c -d ${DISTDIR}/gpg.1.gz > ${WRKSRC}/doc/gpg.1

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
