# New ports collection makefile for:	gnupg
# Version required:	0.9.2
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.ORG
#
# $Id: Makefile,v 1.4 1999/02/07 11:18:51 kuriyama Exp $
#

DISTNAME=	gnupg-0.9.2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.guug.de/pub/gcrypt/ \
		ftp://pgp.iijlab.net/pub/gnupg/ \
		ftp://ftp.win.or.jp/pub/network/gnupg/

MAINTAINER=	kuriyama@FreeBSD.ORG

BROKEN='{standard input}: Assembler messages: Error: Alignment not a power of 2'

RESTRICTED=	"Crypto; export-controlled"

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-included-gettext

MAN1=		gpg.1
MLINKS=		gpg.1 gpgm.1

#post-install:
#	chmod u+s ${PREFIX}/bin/gpg

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
