# New ports collection makefile for:	gnupg
# Version required:	0.9.2
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.ORG
#
# $Id: Makefile,v 1.3 1999/01/15 15:21:30 kuriyama Exp $
#

DISTNAME=	gnupg-0.9.2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.guug.de/pub/gcrypt/ \
		ftp://pgp.iijlab.net/pub/gnupg/ \
		ftp://ftp.win.or.jp/pub/network/gnupg/

MAINTAINER=	kuriyama@FreeBSD.ORG

RESTRICTED=	"Crypto; export-controlled"

USE_AUTOCONF=	YES
CONFIGURE_ARGS=	--with-included-gettext

MAN1=		gpg.1
MLINKS=		gpg.1 gpgm.1

#post-install:
#	chmod u+s ${PREFIX}/bin/gpg

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
