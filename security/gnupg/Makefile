# New ports collection makefile for:	gnupg
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	1.0.6
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/%SUBDIR%/ \
		ftp://pgp.iijlab.net/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/gnupg/&,}
MASTER_SITE_SUBDIR=	gnupg

MAINTAINER=	kuriyama@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

#RESTRICTED=	"Crypto; export-controlled"
GNU_CONFIGURE=	YES
MAN1=		gpg.1 gpgv.1
MLINKS=		gpg.1 gpgm.1

.include <bsd.port.pre.mk>

.if exists(${PREFIX}/lib/libiconv.so)
LIB_DEPENDS+=	iconv.2:${PORTSDIR}/converters/iconv
.endif
.if exists(${PREFIX}/lib/libgdbm.so)
LIB_DEPENDS+=	gdbm.2:${PORTSDIR}/databases/gdbm
.endif

.if ${OSVERSION} < 300000
USE_GMAKE=	YES
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
	@${CAT} ${PKGMESSAGE}

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.post.mk>
