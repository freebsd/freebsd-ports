# New ports collection makefile for:	gnupg
# Version required:	0.9.5
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.ORG
#
# $Id: Makefile,v 1.7 1999/03/14 03:12:10 kuriyama Exp $
#

DISTNAME=	gnupg-0.9.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.guug.de/pub/gcrypt/ \
		ftp://pgp.iijlab.net/pub/gnupg/ \
		ftp://ftp.win.or.jp/pub/network/gnupg/

MAINTAINER=	kuriyama@FreeBSD.ORG

#BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake

RESTRICTED=	"Crypto; export-controlled"
#USE_AUTOCONF=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-included-gettext
MAN1=		gpg.1
MLINKS=		gpg.1 gpgm.1

#post-install:
#	chmod u+s ${PREFIX}/bin/gpg

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
