# Ports collection Makefile for:	smurflog
# Version required:			1.0
# Date created:				7/06/1998
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.6 1999/01/07 18:32:45 nectar Exp $
#

DISTNAME=	smurflog-2.1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.bitchx.org/pub/bitchx/files/                 \
		ftp://ftp.buk.net/pub/software/bitchx/files/           \
		http://www.nectar.cc/distfiles/

MAINTAINER=	nectar@FreeBSD.ORG

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.smurflog
	${INSTALL_PROGRAM} ${WRKSRC}/smurflog ${PREFIX}/sbin/smurflog

.include <bsd.port.mk>
